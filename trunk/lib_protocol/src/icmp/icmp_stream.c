#include "StdAfx.h"
#include "icmp_struct.h"
#include "icmp_private.h"

static int icmp_read(ACL_VSTREAM *stream, void *buf, size_t size,
	int timeout acl_unused, void *arg)
{
	ICMP_STREAM *is = (ICMP_STREAM*) arg;
	int   ret;

#ifdef ACL_UNIX
	ret = recvfrom(ACL_VSTREAM_SOCK(stream), buf, size, 0,
		(struct sockaddr*) &is->from, (socklen_t*) &is->from_len);
#elif defined(WIN32)
	ret = recvfrom(ACL_VSTREAM_SOCK(stream), (char*) buf, (int) size,
		0, (struct sockaddr*) &is->from, &is->from_len);
#else
#error "unknown OS"
#endif
	if (ret < 0)
		acl_msg_error("%s(%d): recvfrom error(%s)",
			__FILE__, __LINE__, acl_last_serror());
	return (ret);
}

static int icmp_write(ACL_VSTREAM *stream, const void *buf, size_t size,
	int timeout acl_unused, void *arg)
{
	ICMP_STREAM *is = (ICMP_STREAM*) arg;
	int   ret;

#ifdef ACL_UNIX
	ret = sendto(ACL_VSTREAM_SOCK(stream), buf, size, 0,
		(struct sockaddr*) &is->curr_host->dest,
		sizeof(is->curr_host->dest));
#elif defined(WIN32)
	ret = sendto(ACL_VSTREAM_SOCK(stream), (const char*) buf, (int) size, 0,
		(struct sockaddr*) &is->curr_host->dest,
		sizeof(is->curr_host->dest));
#else
#error	"unknown OS"
#endif
	return (ret);
}

void icmp_stream_close(ICMP_STREAM* is)
{
	if (is->astream)
		acl_aio_iocp_close(is->astream);
	else if (is->vstream)
		acl_vstream_close(is->vstream);
	acl_myfree(is);
}

ICMP_STREAM* icmp_stream_open(ACL_AIO *aio)
{
	const char* myname = "icmp_stream_open";
	ACL_SOCKET fd;
	ICMP_STREAM *is = (ICMP_STREAM*) acl_mycalloc(1, sizeof(ICMP_STREAM));

	is->from_len = sizeof(is->from);

	/* 创建通信流 */

	fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (fd == ACL_SOCKET_INVALID)
		acl_msg_fatal("%s(%d): socket create error", myname, __LINE__);

	is->vstream = acl_vstream_fdopen(fd, O_RDWR, 1024, 0, ACL_VSTREAM_TYPE_SOCK);
	acl_vstream_ctl(is->vstream,
		ACL_VSTREAM_CTL_READ_FN, icmp_read,
		ACL_VSTREAM_CTL_WRITE_FN, icmp_write,
		ACL_VSTREAM_CTL_CONTEXT, is,
		ACL_VSTREAM_CTL_END);

	/* 如果采用异步方式，则打开异步流 */
	if (aio)
		is->astream = acl_aio_open(aio, is->vstream);

	return (is);
}

void icmp_stream_reopen(ACL_AIO *aio, ICMP_STREAM *is)
{
	ACL_SOCKET fd = ACL_VSTREAM_SOCK(is->vstream);
	ACL_VSTREAM_SOCK(is->vstream) = ACL_SOCKET_INVALID; /* 防止原SOCKET被关闭:) */

	is->vstream = acl_vstream_fdopen(fd, O_RDWR, 1024, 0, ACL_VSTREAM_TYPE_SOCK);
	acl_vstream_ctl(is->vstream,
		ACL_VSTREAM_CTL_READ_FN, icmp_read,
		ACL_VSTREAM_CTL_WRITE_FN, icmp_write,
		ACL_VSTREAM_CTL_CONTEXT, is,
		ACL_VSTREAM_CTL_END);

	if (aio)
		is->astream = acl_aio_open(aio, is->vstream);
}
