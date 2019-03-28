#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Decryptor.h"

TEST_CASE()
{
	std::string html = "<div></div>";
	std::string encodeHtml = "&lt;div&gt;&lt;/div&gt;";

	CHECK(HtmlEncode(html) == encodeHtml);
}