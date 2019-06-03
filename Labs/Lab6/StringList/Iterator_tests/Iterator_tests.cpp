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

	--it;

	/*auto afterDec = --it;
	CHECK(*afterDec == "third");
	CHECK(*it == "third");

	auto beforeDec = it--;
	CHECK(*afterDec == "third");
	CHECK(*it == "second");*/
}

TEST_CASE("Test comparison operators")
{
	CStringList list;

	list.Append("first");
	list.Append("second");
	list.Append("third");

	auto begin = list.begin();
	/*auto it = list.end();
	CHECK(it != begin);

	--it;
	--it;

	CHECK(it == begin);*/
}
