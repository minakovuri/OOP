#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include <string>
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

	CHECK_NOTHROW(arr.Clear());

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
	// ????
	CHECK(copyArr.GetCapacity() == arr.GetCapacity());
}