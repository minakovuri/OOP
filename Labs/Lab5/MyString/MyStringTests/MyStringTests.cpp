#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../MyString/CMyString.h"

void CompareStrings(CMyString const& str, const char* cStr)
{
	CHECK(str.GetLength() == strlen(cStr));
	CHECK(strcmp(str.GetStringData(), cStr) == 0);
}

void CompareStrings(CMyString const& str, std::string& stlStr)
{
	CHECK(str.GetLength() == stlStr.length());
	CHECK(strcmp(str.GetStringData(), stlStr.c_str()) == 0);
}

TEST_CASE("Create with default constructor")
{
	CMyString str;

	CompareStrings(str, "");
}

TEST_CASE("Create from C string")
{
	CMyString str("Hi, everyone!");

	CompareStrings(str, "Hi, everyone!");
}

TEST_CASE("Create from C string with length")
{
	CMyString str("123456789", 9);

	CompareStrings(str, "123456789");
}

TEST_CASE("Create from C string with null element")
{
	CMyString str("1234\056789", 10);

	CHECK(str.GetLength() == 10);
	CHECK(strcmp(str.GetStringData(), "1234\056789") == 0);
}

TEST_CASE("Create with copying from another CMyString")
{
	CMyString str("This is cool!");

	CMyString copyStr(str);

	CompareStrings(copyStr, "This is cool!");

	CHECK(str.GetLength() == copyStr.GetLength());
	CHECK(strcmp(str.GetStringData(), copyStr.GetStringData()) == 0);
}

TEST_CASE("Create from stl string")
{
	std::string stlStr = "Hello, World!";

	CMyString str(stlStr);

	CompareStrings(str, stlStr);
}

TEST_CASE("Create with moving constructor")
{
	CMyString str("Hello, World!");

	CMyString moveStr(std::move(str));

	CompareStrings(moveStr, "Hello, World!");
	CompareStrings(str, "");
}

TEST_CASE("Assign another value")
{
	CMyString s1("SomeString");

	CMyString s2 = s1;

	CompareStrings(s2, "SomeString");

	CHECK(s1.GetLength() == s2.GetLength());
	CHECK(strcmp(s1.GetStringData(), s2.GetStringData()) == 0);
}

TEST_CASE("Try to self-assignment")
{
	CMyString s("SomeString");

	CHECK_NOTHROW(s = s);
}

TEST_CASE("Assign with move")
{
	CMyString str("Hello, World!");

	CMyString moveStr;

	moveStr = std::move(str);

	CompareStrings(moveStr, "Hello, World!");
	CompareStrings(str, "");
}

TEST_CASE("Concat different types of string")
{
	CMyString str;

	CMyString myStr("Hello");
	std::string stlStr(", my name ");
	const char* cStr("is Yury!");

	CHECK_NOTHROW(str = str + myStr);
	CompareStrings(str, "Hello");

	CHECK_NOTHROW(str = str + stlStr);
	CompareStrings(str, "Hello, my name ");

	CHECK_NOTHROW(str = str + cStr);
	CompareStrings(str, "Hello, my name is Yury!");
}

TEST_CASE("Concat with self-assignment")
{
	CMyString str1("Hello,");
	CMyString str2("World!");

	CHECK_NOTHROW(str1 += str2);
	CompareStrings(str1, "Hello,World!");

	CHECK_NOTHROW(str2 += str2);
	CompareStrings(str2, "World!World!");
}

TEST_CASE("Compare strings")
{
	CMyString str1("Not");
	CMyString str2("equal");

	CHECK_FALSE(str1 == str2);
	CHECK(str1 != str2);

	str1 = str2;

	CHECK(str1 == str2);
	CHECK_FALSE(str1 != str2);
}

TEST_CASE("Get chars by index")
{
	CMyString str("Hello, World!");

	std::string expected = "Hello, World!";

	for (size_t i = 0; i < str.GetLength(); i++)
	{
		CHECK(str[i] == expected[i]);
	}

	CHECK_THROWS_AS(str[20], std::out_of_range);
}

TEST_CASE("Clear string")
{
	CMyString str("Hello, World!");

	str.Clear();
	CompareStrings(str, "");

	str = "new";
	CompareStrings(str, "new");
}

TEST_CASE("Get substring")
{
	CMyString str("Hello, World!");

	CHECK(str.SubString(0, 5) == "Hello");
	CHECK(str.SubString(7, 5) == "World");
	CHECK(str.SubString(0, 13) == "Hello, World!");
	CHECK(str.SubString(0, 14) == "Hello, World!");

	CHECK_THROWS_AS(str.SubString(13, 5), std::out_of_range);
}

TEST_CASE("Compare strings (more or less)")
{
	CMyString str1("123");
	CMyString str2("1234");
	CMyString str3("124");

	CHECK(str1 < str2);
	CHECK(str1 < str3);

	CHECK(str2 > str1);
	CHECK(str2 > str3);

	CHECK(str1 <= str2);
	CHECK(str1 <= str3);
	CHECK(str1 <= str1);

	CHECK(str2 >= str1);
	CHECK(str2 >= str3);
	CHECK(str2 >= str2);
}

TEST_CASE("Write to stream")
{
	CMyString str("Hello, World!");

	std::stringstream output;
	output << str;

	auto outputStr = output.str();

	CHECK(outputStr == "Hello, World!");
	CHECK(outputStr.length() == 13);
}

TEST_CASE("Read from stream")
{
	CMyString str;

	std::stringstream input;
	input << "Hello, World!";

	input >> str;
	CompareStrings(str, "Hello,");

	input >> str;
	CompareStrings(str, "World!");
}

TEST_CASE("Loop throw string by iterator from begin to end")
{
	CMyString str("01234");

	int i = 0;

	for (auto it = str.begin(); it != str.end(); it++)
	{
		switch (i)
		{
		case 0:
			CHECK(*it == '0');
			break;
		case 1:
			CHECK(*it == '1');
			break;
		case 2:
			CHECK(*it == '2');
			break;
		case 3:
			CHECK(*it == '3');
			break;
		case 4:
			CHECK(*it == '4');
			break;
		}

		i++;
	}
}

TEST_CASE("Loop throw string by iterator from end to begin")
{
	CMyString str("01234");

	int i = 5;
	auto it = str.end();
	
	do
	{
		it--;
		i--;

		switch (i)
		{
		case 0:
			CHECK(*it == '0');
			break;
		case 1:
			CHECK(*it == '1');
			break;
		case 2:
			CHECK(*it == '2');
			break;
		case 3:
			CHECK(*it == '3');
			break;
		case 4:
			CHECK(*it == '4');
			break;
		}
	} while (it != str.begin());

	CHECK(i == 0);
}

TEST_CASE("Check iterator equals")
{
	CMyString str("Hello, World!");

	CHECK(str.begin() < str.end());
	CHECK(str.end() > str.begin());

	CHECK_FALSE(str.begin() > str.end());
	CHECK_FALSE(str.end() < str.begin());
	CHECK_FALSE(str.begin() == str.end());
}

TEST_CASE("Addition of an iterator with a number and numbers with an iterator")
{
	CMyString str("Hello, World!");

	auto it = str.begin();

	CHECK(*(it + 2) == 'l');
	CHECK(*(it + 3) == 'l');
	CHECK(*(it + 4) == 'o');

	CHECK(*(2 + it) == 'l');
	CHECK(*(3 + it) == 'l');
	CHECK(*(4 + it) == 'o');
}