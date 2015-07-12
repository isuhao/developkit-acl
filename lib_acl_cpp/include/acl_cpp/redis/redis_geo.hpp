#pragma once
#include "acl_cpp/acl_cpp_define.hpp"
#include <vector>
#include <map>
#include "acl_cpp/redis/redis_command.hpp"

namespace acl
{

#define GEO_INVALID_POS	360

enum
{
	GEO_UNIT_FT,
	GEO_UNIT_M,
	GEO_UNIT_MI,
	GEO_UNIT_KM,
};

enum
{
	GEO_WITH_COORD = 1 << 0,
	GEO_WITH_DIST  = 1 << 1,
	GEO_WITH_HASH  = 1 << 2,
};

enum
{
	GEO_SORT_NONE,
	GEO_SORT_ASC,
	GEO_SORT_DESC,
};

class ACL_CPP_API geo_pos
{
public:
	geo_pos(const char* name);
	geo_pos(const geo_pos& pos);
	~geo_pos();

	void set_name(const char* name);
	const char* get_name() const
	{
		return name_.c_str();
	}

	void set_dist(double dist);
	double get_dist() const
	{
		return dist_;
	}

#if defined(_WIN32) || defined(_WIN64)
	void set_hash(__int64 hash);
	__int64 get_hash() const
#else
	void set_hash(long long int hash);
	long long int get_hash() const
#endif // defined(_WIN32) || defined(_WIN64)
	{
		return hash_;
	}

	void set_longitude(double longitude);
	double get_longitude() const
	{
		return longitude_;
	}

	void set_latitude(double latitude);
	double get_latitude() const
	{
		return latitude_;
	}

private:
	string name_;
	double dist_;
#if defined(_WIN32) || defined(_WIN64)
	__int64 hash_;
#else
	long long int hash_;
#endif // defined(_WIN32) || defined(_WIN64)

	double longitude_;
	double latitude_;
};

class redis_client;

class ACL_CPP_API redis_geo : virtual public redis_command
{
public:
	/**
	 * see redis_command::redis_command()
	 */
	redis_geo();

	/**
	 * see redis_command::redis_command(redis_client*)
	 */
	redis_geo(redis_client* conn);

	/**
	 * see redis_command::redis_command(redis_client_cluster*， size_t)
	 */
	redis_geo(redis_client_cluster* cluster, size_t max_conns);
	virtual ~redis_geo();

	/////////////////////////////////////////////////////////////////////

	/**
	 * 添加一个指定的地理位置坐标至指定的 key 中
	 * Add the specified geospatial item (latitude, logitude, name)
	 * to the specified key.
	 * @param key {const char*} 对应的键值
	 *  the specified key
	 * @param member {const char*} 该地理坐标的标识符
	 *  the geospatial's identifier
	 * @param loginitude {double} 经度
	 *  the geospatial's loginitude
	 * @param latitude {double} 纬度
	 *  the geospatial's latitude
	 * @return {int} 1：添加成功，0：该地理坐标标识符已存在，即使对其值进行了修改，
	 *  也将返回 0，-1：表示出错。
	 *  the return value as below:
	 *  1: add one new member successfully
	 *  0: the member already existed, and the geospatial may be changed
	 * -1: some erro happened
	 */
	int geoadd(const char* key, const char* member,
		double longitude, double latitude);

	/**
	 * 给指定 key 添加一组地址位置坐标数据
	 * Add the specified geospatial items (latitude, logitude, name)
	 * to the specified key.
	 * @param key {const char*} 对应的键值
	 *  the specified key
	 * @param size {size_t} 数组的长度
	 *  the array's size
	 * @param memebers {const char* []} 成员数组，其长度由 size 指定
	 *  the members array, which's length was specified by size parameter
	 * @param longitudes {const double[]} 经度数据数组，其长度由 size 指定
	 *  the logintitudes array, which's length was specifed by size parameter
	 * @param latitudes {const double[]} 纬度数据数组，其长度由 size 指定
	 *  the lattitudes array, which's length was specifed by size parameter
	 * @return {int} 添加成功的成员数量，返回值含义如下：
	 *  return the successfully added members's count:
	 *  > 0: 表示成功添加的成员数量；
	 *       represent the successfully added memebers's count
	 *    0: 这些成员都已经存在
	 *       the members's belong the key already existing
	 *   -1: 表示出错，可以通过 result_error 函数查看出错原因
	 *       some error happened, the result_error function can be used
	 *       to find the error's reason
	 */
	int geoadd(const char* key, size_t size, const char* memebers[],
		const double longitudes[], const double latitudes[]);

	/**
	 * 给指定 key 添加一组地址位置坐标数据
	 * Add the specified geospatial items (latitude, logitude, name)
	 * to the specified key.
	 * @param key {const char*} 对应的键值
	 *  the specified key
	 * @param memebers {const std::vector<string>&} 成员数组
	 *  the members array
	 * @param longitudes {const std::vector<double>&} 经度数据数组
	 *  the logintitudes array
	 * @param latitudes {const std::vector<double>&} 纬度数据数组
	 *  the lattitudes array
	 * @return {int} 添加成功的成员数量，返回值含义如下：
	 *  return the successfully added members's count:
	 *  > 0: 表示成功添加的成员数量；
	 *       represent the successfully added memebers's count
	 *    0: 这些成员都已经存在
	 *       the members's belong the key already existing
	 *   -1: 表示出错，可以通过 result_error 函数查看出错原因
	 *       some error happened, the result_error function can be used
	 *       to find the error's reason
	 *  注意：三个数组(members, longitudes, latitudes)的数组长度必须相等
	 *  Notice: the three array's length must be equal between members,
	 *    longitudes and latitudes
	 */
	int geoadd(const char* key, const std::vector<string>& members,
		const std::vector<double>& longitudes,
		const std::vector<double>& latitudes);

	bool geohash(const char* key, const std::vector<string>& members,
		std::vector<string>& results);
	bool geopos(const char* key, const std::vector<string>& members,
		std::vector<std::pair<double, double> >& results);

	double geodist(const char* key, const char* member1,
		const char* member2, int unit = GEO_UNIT_M);
	const std::vector<geo_pos>& georadius(const char* key,
		double longitude, double latitude, double radius,
		int unit = GEO_UNIT_M,
		int with = GEO_WITH_COORD | GEO_WITH_DIST,
		int sort = GEO_SORT_ASC);
	const std::vector<geo_pos>& georadiusbymember(const char* key,
		const char* member, double radius,
		int unit = GEO_UNIT_M,
		int with = GEO_WITH_COORD | GEO_WITH_DIST,
		int sort = GEO_SORT_ASC);

private:
	std::vector<geo_pos> positions_;

	void add_one_pos(const redis_result& rr);

	static const char* get_unit(int unit);
};

} // namespace acl
