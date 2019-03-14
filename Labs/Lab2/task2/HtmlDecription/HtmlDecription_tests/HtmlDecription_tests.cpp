#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Decryptor.h"

TEST_CASE("Test HtmlEncode() function")
{
	{
		const std::string html = "<div>\n</div>";
		const std::string encodeHtml = "&lt;div&gt;\n&lt;/div&gt;";
		REQUIRE(HtmlEncode(html) == encodeHtml);
	}
}