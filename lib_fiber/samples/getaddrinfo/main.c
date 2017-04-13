#include "lib_acl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fiber/lib_fiber.h"

static char  __dns_ip[256];
static int   __dns_port = 53;
static int   __count = 0;

static void getip(struct addrinfo *res, char *ip, size_t size)
{
	ip[0] = 0;

	if (res->ai_family == AF_INET) {
		struct sockaddr_in *in = (struct sockaddr_in *) res->ai_addr;
		if (!inet_ntop(res->ai_family, &in->sin_addr.s_addr,
			ip, size))
		{
			printf(">>>inet_ntop for ipv4 error\r\n");
		}
	} else if (res->ai_family == AF_INET6) {
		struct sockaddr_in6 *in6 = (struct sockaddr_in6 *) res->ai_addr;
		if (!inet_ntop(res->ai_family, &in6->sin6_addr, ip, size)) {
			printf(">>>inet_ntop for ipv6 error\r\n");
		}
	}
}

static void nslookup(ACL_FIBER *fiber acl_unused, void *ctx)
{
	const char *addr = (const char *) ctx;
	struct addrinfo hints, *res0;
	int  err;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_V4MAPPED | AI_ADDRCONFIG;

	printf(">>> nslookup: %s\r\n", addr);

	if ((err = getaddrinfo(addr, "finger", &hints, &res0))) {
		printf(">>> result: getaddrinfo error=%s, name=%s\r\n",
			gai_strerror(err), addr);
	} else {
		struct addrinfo *res;
		for (res = res0; res; res = res->ai_next) {
			char ip[64];
			getip(res, ip, sizeof(ip));

			printf(">>> result: host: %s, ai_family: %d, ip: %s\r\n",
				addr, res->ai_family, ip);
		}

		freeaddrinfo(res0);
	}

	--__count;

	if (__count == 0)
		acl_fiber_schedule_stop();
}

static void usage(const char *procname)
{
	printf("usage: %s -h [help] -n addrs -a dns_ip -p dns_port\r\n", procname);
}

int main(int argc, char *argv[])
{
	int   ch;
	char  buf[1024];
	ACL_ARGV *tokens;
	ACL_ITER  iter;

	buf[0] = 0;
	__dns_ip[0] = 0;

	while ((ch = getopt(argc, argv, "hn:a:p:")) > 0) {
		switch (ch) {
		case 'h':
			usage(argv[0]);
			return 0;
		case 'n':
			snprintf(buf, sizeof(buf), "%s", optarg);
			break;
		case 'a':
			snprintf(__dns_ip, sizeof(__dns_ip), "%s", optarg);
			break;
		case 'p':
			__dns_port = atoi(optarg);
			break;
		default:
			break;
		}
	}

	if (buf[0] == 0) {
		usage(argv[0]);
		return 0;
	}

	tokens = acl_argv_split(buf, ";, \t");
	__count = tokens->argc;

	acl_foreach(iter, tokens) {
		char* addr = (char* ) iter.data;
		acl_fiber_create(nslookup, addr, 32000);
	}

	acl_fiber_schedule();

	acl_argv_free(tokens);

	return 0;
}
