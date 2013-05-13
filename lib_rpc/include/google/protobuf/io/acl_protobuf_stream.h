#pragma once

#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/stubs/common.h>
#include "acl_cpp/stream/istream.hpp"
#include "acl_cpp/stream/ofstream.hpp"

namespace google {
namespace protobuf {
namespace io {

class LIBPROTOBUF_EXPORT AclInputStream : public ZeroCopyInputStream
{
public:
	explicit AclInputStream(acl::istream* in, int block_size = -1);
	~AclInputStream();

	//基类 ZeroCopyInputStream 虚函数实现
	bool Next(const void** data, int* size);
	void BackUp(int count);
	bool Skip(int count);
	int64 ByteCount() const;
private:
	class LIBPROTOBUF_EXPORT CopyingAclInputStream : public CopyingInputStream
	{
	public:
		CopyingAclInputStream(acl::istream* input);
		~CopyingAclInputStream();

		// implements CopyingInputStream
		int Read(void* buffer, int size);
		// (We usse the default implementation of Skip().)

	private:
		acl::istream* input_;

		GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(CopyingAclInputStream);
	};

	CopyingAclInputStream copying_input_;
	CopyingInputStreamAdaptor impl_;

	GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(AclInputStream);
};

class LIBPROTOBUF_EXPORT AclOutputStream : public ZeroCopyOutputStream
{
public:
	explicit AclOutputStream(acl::ostream* output, int block_size = -1);
	~AclOutputStream();

	bool Flush();

	//基类 ZeroCopyInputStream 虚函数实现
	bool Next(void** data, int* size);
	void BackUp(int count);
	int64 ByteCount() const;
private:
	class LIBPROTOBUF_EXPORT CopyingAclOutputStream : public CopyingOutputStream
	{
	public:
		CopyingAclOutputStream(acl::ostream* output);
		~CopyingAclOutputStream();

		// implements CopyingOutputStream
		bool Write(const void* buffer, int size);

	private:
		acl::ostream* output_;

		GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(CopyingAclOutputStream);
	};

	CopyingAclOutputStream copying_output_;
	CopyingOutputStreamAdaptor impl_;

	GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(AclOutputStream);
};

}  // namespace io
}  // namespace protobuf
}  // namespace google
