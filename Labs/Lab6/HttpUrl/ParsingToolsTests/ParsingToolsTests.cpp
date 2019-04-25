#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../HttpUrl/CUrlParsingError.h"
#include "../HttpUrl/ParsingTools.h"

TEST_CASE("Test ParseProtocol function")
{
	CHECK(ParseProtocol("http://mail.ru/index.html") == Protocol::HTTP);
	CHECK(ParseProtocol("https://google.com/index.html") == Protocol::HTTPS);

	CHECK(ParseProtocol("HTTP://mail.ru/index.html") == Protocol::HTTP);
	CHECK(ParseProtocol("HTTPS://google.com/index.html") == Protocol::HTTPS);

	CHECK_THROWS_AS(ParseProtocol("mail.ru/index.html"), CUrlParsingError);
	CHECK_THROWS_AS(ParseProtocol("://mail.ru/index.html"), CUrlParsingError);
	CHECK_THROWS_AS(ParseProtocol("htpps://mail.ru/index.html"), CUrlParsingError);
}

TEST_CASE("Test ParseDomain function")
{
	CHECK(ParseDomain("http://mail.ru/index.html") == "mail.ru");
	CHECK(ParseDomain("HTTP://mail.ru") == "mail.ru");
	CHECK(ParseDomain("HTTP://mail.ru:8000") == "mail.ru");
	CHECK(ParseDomain("http://www.mail.ru/index.html") == "www.mail.ru");

	CHECK_THROWS_AS(ParseDomain("http://:8000"), CUrlParsingError);
	CHECK_THROWS_AS(ParseDomain("http://mail.ru?"), CUrlParsingError);
	CHECK_THROWS_AS(ParseDomain("htpps://"), CUrlParsingError);
}

TEST_CASE("Test ParsePort function")
{
	CHECK(ParsePort("HTTP://mail.ru:80") == 80);
	CHECK(ParsePort("mail.ru:1000") == 1000);
	CHECK(ParsePort("http://mail.ru:586/index.html") == 586);

	CHECK_THROWS_AS(ParsePort("http://mail.ru:100000"), CUrlParsingError);
	CHECK_THROWS_AS(ParsePort("http://mail.ru:-1"), CUrlParsingError);
}

TEST_CASE("Test ParseDocument function")
{
	CHECK(ParseDocument("http://mail.ru:586/index.html") == "/index.html");
	CHECK(ParseDocument("mail.ru/images/photo.jpg") == "/images/photo.jpg");
	CHECK(ParseDocument("mail.ru") == "/");

	CHECK_THROWS_AS(ParseDocument("http://mail.ru/&index.html"), CUrlParsingError);
}
