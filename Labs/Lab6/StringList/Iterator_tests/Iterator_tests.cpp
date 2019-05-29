#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../StringList/CStringList.h"

TEST_CASE("Test * operator")
{
	CStringList list;

	list.Append("first");
	list.Append("second");
	list.Append("third");

	auto begin = list.begin();

	CHECK(*begin == "first");
}

TEST_CASE("Test -> operator")
{
	CStringList list;

	list.Append("first");
	list.Append("second");
	list.Append("third");

	auto begin = list.begin();

	CHECK(begin->data == "first");
}

TEST_CASE("Test increment operators")
{
	CStringList list;

	list.Append("first");
	list.Append("second");
	list.Append("third");

	auto it = list.begin();

	auto beforeInc = it++;
	CHECK(*beforeInc == "first");
	CHECK(*it == "second");

	auto afterInc = ++it;
	CHECK(*afterInc == "third");
	CHECK(*it == "third");
}

TEST_CASE("Test decrement operators")
{
	CStringList list;

	list.Append("first");
	list.Append("second");
	list.Append("third");

	auto it = list.end();

	auto beforeDec = it--;
	CHECK(*beforeDec == "third");
	CHECK(*it == "second");

	auto afterDec = --it;
	CHECK(*afterDec == "first");
	CHECK(*it == "first");
}

TEST_CASE("Test comparison operators")
{
	CStringList list;

	list.Append("first");
	list.Append("second");
	list.Append("third");

	auto begin = list.begin();
	auto it = list.end();
	CHECK(it != begin);

	--it;
	--it;

	CHECK(it == begin);
}