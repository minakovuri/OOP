#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../StringList/CStringList.h"

TEST_CASE("Create empty list")
{
	CStringList list;

	CHECK(list.GetSize() == 0u);
	CHECK(list.IsEmpty());
}

TEST_CASE("Adding items at the end of list")
{
	CStringList list;
	auto listSize = list.GetSize();

	list.Append("Hello");
	CHECK(list.GetSize() == ++listSize);

	list.Append("World");
	CHECK(list.GetSize() == ++listSize);
}

TEST_CASE("Get last elements of list")
{
	CStringList list;

	list.Append("hello");
	CHECK(list.GetLastElement() == "hello");

	list.Append("goodbye");
	CHECK(list.GetLastElement() == "goodbye");
}

TEST_CASE("Add elements to list and then clear it")
{
	CStringList list;

	list.Append("some");
	list.Append("interesting");
	list.Append("text");

	list.Clear();
	CHECK(list.GetSize() == 0u);
}

/*TEST_CASE("Test iterators and const iterators")
{
	CStringList list;

	list.Append("first");
	list.Append("second");
	list.Append("third");

	CHECK(*list.begin() == "first");
	CHECK(*--list.end() == "third");

	CHECK(*list.cbegin() == "first");
	CHECK(*list.cend() == "third");
}*/

/*TEST_CASE("Push element at the begin of list")
{
	CStringList list;

	list.Append("element");

	list.PushFront("first push");
	CHECK(*list.begin() == "first push");
	CHECK(*--list.end() == "element");

	list.PushFront("second push");
	CHECK(*list.begin() == "second push");
	CHECK(*--list.end() == "element");

	list.PushFront("third push");
	CHECK(*list.begin() == "third push");
	CHECK(*--list.end() == "element");
}*/

/*TEST_CASE("Insert item at position specified by iterator")
{
	CStringList list;

	list.Append("one");
	list.Append("two");
	list.Append("three");

	list.Insert(list.begin(), "start");
	list.Insert(list.end(), "end");

	CHECK(*list.begin() == "start");
	CHECK(*list.end() == "end");

	auto it = list.begin();
	++it;
	++it;
	list.Insert(it, "new");

	std::vector<std::string> expectedElements = {
		"start",
		"one",
		"new",
		"two",
		"three",
		"end",
	};

	size_t i = 0;
	for (auto el : list)
	{
		CHECK(el == expectedElements[i]);
		i++;
	}
}*/
