#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../HttpUrl/CHttpUrl.h"
#include "../HttpUrl/CUrlParsingError.h"

TEST_CASE("Create CHttpUrl instance with valid domain, document, protocol and port as constructor parameters")
{
	CHttpUrl httpUrl("my.ru", "/index.html", Protocol::HTTP, 8081);

	CHECK(httpUrl.GetProtocol() == Protocol::HTTP);
	CHECK(httpUrl.GetDomain() == "my.ru");
	CHECK(httpUrl.GetPort() == 8081);
	CHECK(httpUrl.GetDocument() == "/index.html");
}

TEST_CASE("Create CHttpUrl instance with valid domain, document and protocol as constructor parameters")
{
	CHttpUrl httpUrl("my.ru", "/index.html", Protocol::HTTPS);

	CHECK(httpUrl.GetProtocol() == Protocol::HTTPS);
	CHECK(httpUrl.GetDomain() == "my.ru");
	CHECK(httpUrl.GetPort() == DEFAULT_HTTPS_PORT);
	CHECK(httpUrl.GetDocument() == "/index.html");
}

TEST_CASE("Create CHttpUrl instance with valid domain and document as constructor parameters")
{
	CHttpUrl httpUrl("my.ru", "/index.html");

	CHECK(httpUrl.GetProtocol() == Protocol::HTTP);
	CHECK(httpUrl.GetDomain() == "my.ru");
	CHECK(httpUrl.GetPort() == DEFAULT_HTTP_PORT);
	CHECK(httpUrl.GetDocument() == "/index.html");
}

TEST_CASE("Trying to create CHttpUrl with incorrect domain and document as parameters")
{
	CHECK_THROWS_AS(CHttpUrl("&my.ru", "/index.html"), std::invalid_argument);
	CHECK_THROWS_AS(CHttpUrl("my.ru", "'index.html"), std::invalid_argument);
	CHECK_THROWS_AS(CHttpUrl("my.ru", "index.html:", Protocol::HTTP, 8081), std::invalid_argument);
	CHECK_THROWS_AS(CHttpUrl("!my.ru", "index?.html:", Protocol::HTTP), std::invalid_argument);
}

TEST_CASE("Create CHttpUrl instance with valid url, includes domain and document as constructor parameters")
{
	CHttpUrl httpUrl("my.ru/index.html");

	CHECK(httpUrl.GetProtocol() == Protocol::HTTP);
	CHECK(httpUrl.GetDomain() == "my.ru");
	CHECK(httpUrl.GetPort() == DEFAULT_HTTP_PORT);
	CHECK(httpUrl.GetDocument() == "/index.html");

	CHECK(httpUrl.GetURL() == "http://my.ru/index.html");
}

TEST_CASE("Create CHttpUrl instance with valid full url as constructor parameters")
{
	CHttpUrl httpUrl("https://my.ru:8081/img/rectangle.png");

	CHECK(httpUrl.GetProtocol() == Protocol::HTTPS);
	CHECK(httpUrl.GetDomain() == "my.ru");
	CHECK(httpUrl.GetPort() == 8081);
	CHECK(httpUrl.GetDocument() == "/img/rectangle.png");

	CHECK(httpUrl.GetURL() == "https://my.ru:8081/img/rectangle.png");
}

TEST_CASE("Create CHttpUrl instance with valid url, includes protocol and domain as constructor parameters")
{
	CHttpUrl httpUrl("https://my.ru:443");

	CHECK(httpUrl.GetProtocol() == Protocol::HTTPS);
	CHECK(httpUrl.GetDomain() == "my.ru");
	CHECK(httpUrl.GetPort() == DEFAULT_HTTPS_PORT);
	CHECK(httpUrl.GetDocument() == "/");

	CHECK(httpUrl.GetURL() == "https://my.ru/");
}

TEST_CASE("Trying to create CHttpUrl with invalid url as parameter")
{
	CHECK_THROWS_AS(CHttpUrl("https:/mail.ru"), CUrlParsingError);
}