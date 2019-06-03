#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../StringStack/CStringStack.h"

TEST_CASE("Create empty stack")
{
	CStringStack stack;

	CHECK(stack.GetSize() == 0);
	CHECK(stack.IsEmpty());
	CHECK_THROWS_AS(stack.GetTop(), std::logic_error);
}

TEST_CASE("Push values")
{
	CStringStack stack;

	CHECK_NOTHROW(stack.Push("first"));
	CHECK_FALSE(stack.IsEmpty());
	CHECK(stack.GetSize() == 1);
	CHECK(stack.GetTop() == "first");

	CHECK_NOTHROW(stack.Push("second"));
	CHECK_FALSE(stack.IsEmpty());
	CHECK(stack.GetSize() == 2);
	CHECK(stack.GetTop() == "second");
}

TEST_CASE("Pop values")
{
	CStringStack stack;

	stack.Push("first");
	stack.Push("second");
	stack.Push("third");

	CHECK_NOTHROW(stack.Pop());
	CHECK_FALSE(stack.IsEmpty());
	CHECK(stack.GetSize() == 2);
	CHECK(stack.GetTop() == "second");

	CHECK_NOTHROW(stack.Pop());
	CHECK_FALSE(stack.IsEmpty());
	CHECK(stack.GetSize() == 1);
	CHECK(stack.GetTop() == "first");

	CHECK_NOTHROW(stack.Pop());
	CHECK(stack.GetSize() == 0);
	CHECK(stack.IsEmpty());
	CHECK_THROWS_AS(stack.GetTop(), std::logic_error);

	CHECK_THROWS_AS(stack.Pop(), std::logic_error);
}

TEST_CASE("Clear stack")
{
	CStringStack stack;

	stack.Push("first");
	stack.Push("second");
	stack.Push("third");

	stack.Clear();

	CHECK(stack.GetSize() == 0);
	CHECK(stack.IsEmpty());
	CHECK_THROWS_AS(stack.GetTop(), std::logic_error);

	CHECK_NOTHROW(stack.Push("new"));
	CHECK_FALSE(stack.IsEmpty());
	CHECK(stack.GetSize() == 1);
	CHECK(stack.GetTop() == "new");
}

TEST_CASE("Create stack with copying constructor")
{
	CStringStack stack;

	CHECK_NOTHROW(CStringStack(stack));

	stack.Push("first");
	stack.Push("second");
	stack.Push("third");

	CStringStack copyStack(stack);

	CHECK(copyStack.GetSize() == stack.GetSize());
	CHECK(copyStack.GetTop() == stack.GetTop());
}

TEST_CASE("Create stack with moving constructor")
{
	CStringStack stack1;

	stack1.Push("first");
	stack1.Push("second");
	stack1.Push("third");

	CStringStack stack2(std::move(stack1));

	CHECK(stack1.IsEmpty());

	CHECK(stack2.GetTop() == "third");
	CHECK_NOTHROW(stack2.Pop());
	CHECK(stack2.GetTop() == "second");
	CHECK_NOTHROW(stack2.Pop());
	CHECK(stack2.GetTop() == "first");
}

TEST_CASE("Test copying assignment operator")
{
	CStringStack stack1;
	stack1.Push("first");
	stack1.Push("second");

	CStringStack stack2;
	CHECK_NOTHROW(stack2 = stack1);

	CHECK(stack2.GetSize() == stack1.GetSize());
	CHECK(stack2.GetTop() == stack1.GetTop());

	auto stackSize = stack1.GetSize();
	CHECK_NOTHROW(stack1 = stack1);
	CHECK(stack1.GetSize() == stackSize);

	stack1.Push("third");

	CHECK_NOTHROW(stack2 = stack1);
	CHECK(stack2.GetSize() == stack1.GetSize());
	CHECK(stack2.GetTop() == stack1.GetTop());
}

TEST_CASE("Test moving assignment operator")
{
	CStringStack stack1;
	stack1.Push("first");
	stack1.Push("second");

	CStringStack stack2;
	CHECK_NOTHROW(stack2 = std::move(stack1));

	auto stackSize = stack1.GetSize();
	CHECK_NOTHROW(stack1 = std::move(stack1));
	CHECK(stack1.GetSize() == stackSize);

	stack1.Push("third");

	CHECK_NOTHROW(stack2 = std::move(stack1));
}