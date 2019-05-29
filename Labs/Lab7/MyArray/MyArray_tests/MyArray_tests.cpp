#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../MyArray/CMyArray.h"

float GetRandomFloat(float X)
{
	return static_cast<float>(RAND_MAX / X);
}

TEST_CASE("Test default constructor array")
{
	CMyArray<std::string> arr;
	CHECK(arr.GetSize() == 0);
	CHECK(arr.GetCapacity() == 0);
}

TEST_CASE("Test adding item to array")
{
	CMyArray<std::string> arr;

	arr.Append(std::string("first string"));
	CHECK(arr.GetSize() == 1);
	CHECK(arr.GetCapacity() == 1);

	arr.Append(std::string("second string"));
	CHECK(arr.GetSize() == 2);
	CHECK(arr.GetCapacity() == 2);

	arr.Append(std::string("third string"));
	CHECK(arr.GetSize() == 3);
	CHECK(arr.GetCapacity() == 4);

	arr.Append(std::string("fourth string"));
	CHECK(arr.GetSize() == 4);
	CHECK(arr.GetCapacity() == 4);
}

TEST_CASE("Array cleaning test")
{
	CMyArray<float> arr;

	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));

	arr.Clear();

	CHECK(arr.GetSize() == 0);
}

TEST_CASE("Test copying array constructor")
{
	CMyArray<float> arr;

	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));

	CMyArray<float> copyArr(arr);

	CHECK(copyArr.GetSize() == arr.GetSize());
	CHECK(copyArr.GetCapacity() == arr.GetSize());
}

TEST_CASE("Test moving array constructor")
{
	CMyArray<float> arr1;

	arr1.Append(1);
	arr1.Append(2);
	arr1.Append(3);

	CMyArray<float> arr2(std::move(arr1));

	CHECK(arr2[0] == 1);
	CHECK(arr2[1] == 2);
	CHECK(arr2[2] == 3);
	CHECK(arr1.GetSize() == 0);
}

TEST_CASE("Test access index operator")
{
	CMyArray<int> arr;

	arr.Append(1);
	arr.Append(2);
	arr.Append(3);
	arr.Append(4);

	CHECK_NOTHROW(arr[0] = 0);
	CHECK_NOTHROW(arr[1] = 1);
	CHECK_NOTHROW(arr[2] = 10);
	CHECK_NOTHROW(arr[3] = 11);

	CHECK(arr[0] == 0);
	CHECK(arr[1] == 1);
	CHECK(arr[2] == 10);
	CHECK(arr[3] == 11);

	CHECK_THROWS_AS(arr[4], std::out_of_range);
}

TEST_CASE("Test resize array method")
{
	CMyArray<std::string> arr;

	arr.Append("first");
	arr.Append("second");
	arr.Append("third");

	CHECK_NOTHROW(arr.Resize(1));
	CHECK(arr.GetSize() == 1);

	CHECK_NOTHROW(arr.Resize(3));
	CHECK(arr.GetSize() == 3);

	CHECK(arr[0] == "first");
	CHECK(arr[1] == "");
	CHECK(arr[2] == "");

	CHECK_NOTHROW(arr.Resize(0));
	CHECK(arr.GetSize() == 0);

	CHECK_NOTHROW(arr.Resize(1000));
	CHECK(arr.GetSize() == 1000);
}

TEST_CASE("Test assignment operator")
{
	CMyArray<int> arr1;
	arr1.Append(1);
	arr1.Append(2);

	CMyArray<int> arr2;
	CHECK_NOTHROW(arr2 = arr1);

	CHECK(arr2.GetSize() == 2);
	CHECK(arr2[0] == 1);
	CHECK(arr2[1] == 2);

	auto arrSize = arr1.GetSize();
	CHECK_NOTHROW(arr1 = arr1);
	CHECK(arr1.GetSize() == arrSize);
}

TEST_CASE("Test moving assignment operator")
{
	CMyArray<int> arr1;
	arr1.Append(1);
	arr1.Append(2);

	CMyArray<int> arr2;
	CHECK_NOTHROW(arr2 = std::move(arr1));

	CHECK(arr2.GetSize() == 2);
	CHECK(arr2[0] == 1);
	CHECK(arr2[1] == 2);

	auto arrSize = arr1.GetSize();
	CHECK_NOTHROW(arr1 = std::move(arr1));
	CHECK(arr1.GetSize() == arrSize);
}

TEST_CASE("Test begin iterator")
{
	CMyArray<float> arr;

	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));

	auto it = arr.begin();
	CHECK(*it == arr[0]);
}

TEST_CASE("Test rbegin iterator")
{
	CMyArray<float> arr;

	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));

	auto it = arr.rbegin();
	CHECK(*it == arr[2]);

	++it;
	CHECK(*it == arr[1]);

	--it;
	CHECK(*it == arr[2]);
}

TEST_CASE("Test end iterator")
{
	CMyArray<float> arr;

	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));

	auto end = arr.end();
	--end;
	CHECK(*end == arr[2]);
}

TEST_CASE("Test rend iterator")
{
	CMyArray<float> arr;

	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));
	arr.Append(GetRandomFloat(10));

	auto it = arr.rend();

	--it;
	CHECK(*it == arr[0]);

	--it;
	CHECK(*it == arr[1]);

	++it;
	CHECK(*it == arr[0]);
}