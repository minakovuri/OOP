#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../MyArray/CMyArray.h"

struct TestStruct
{
	int x;
};

TEST_CASE("Test * operator")
{
	CMyArray<float> arr;

	arr.Append(12);
	arr.Append(13);
	arr.Append(14);

	auto it = arr.begin();

	CHECK(*it == arr[0]);
}

TEST_CASE("Test -> operator")
{
	CMyArray<TestStruct> arr;

	arr.Append(TestStruct{ 1 });

	auto it = arr.begin();

	CHECK(it->x == 1);
}

TEST_CASE("Test increment operator")
{
	CMyArray<float> arr;

	arr.Append(12);
	arr.Append(13);
	arr.Append(14);

	auto it = arr.begin();

	auto beforeInc = it++;
	CHECK(*beforeInc == arr[0]);
	CHECK(*it == arr[1]);

	auto afterInc = ++it;
	CHECK(*afterInc == arr[2]);
	CHECK(*it == arr[2]);
}

TEST_CASE("Test decrement operator")
{
	CMyArray<float> arr;

	arr.Append(12);
	arr.Append(13);
	arr.Append(14);

	auto it = arr.end();

	auto afterDec = --it;
	CHECK(*afterDec == arr[2]);
	CHECK(*it == arr[2]);

	auto beforeDec = it--;
	CHECK(*beforeDec == arr[2]);
	CHECK(*it == arr[1]);
}

TEST_CASE("Test comparison operators")
{
	CMyArray<float> arr;

	arr.Append(12);
	arr.Append(13);
	arr.Append(14);

	auto begin = arr.begin();
	auto it = arr.end();
	CHECK(begin != it);

	--it;
	--it;
	--it;

	CHECK(begin == it);
}