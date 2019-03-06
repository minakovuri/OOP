#include "pch.h"
#include "Decryptor.h"

#include <iostream>

int main()
{
	std::string textLine;

	while (std::getline(std::cin, textLine))
	{
		std::string encodingHtmlLine = HtmlEncode(textLine);
		std::string decodingHtmlLine = HtmlDecode(encodingHtmlLine);
		std::cout << decodingHtmlLine << std::endl;
	}
}
