#include "pch.h"
#include "HtmlReplacer.h"

std::optional<std::string> GetHtmlEntity(char symbol)
{
	switch (symbol)
	{
	case '\"':
		return "&quot;";
	case '\'':
		return "&apos;";
	case '<':
		return "&lt;";
	case '>':
		return "&gt;";
	case '&':
		return "&amp;";
	default:
		return std::nullopt;
	}
}

std::optional<char> GetSpecialSymbol(std::string& htmlEntity)
{
	if (htmlEntity == "&quot;")
	{
		return '\"';
	}
	else if (htmlEntity == "&apos;")
	{
		return '\'';
	}
	else if (htmlEntity == "&lt;")
	{
		return '<';
	}
	else if (htmlEntity == "&gt;")
	{
		return '>';
	}
	else if (htmlEntity == "&amp;")
	{
		return '&';
	}

	return std::nullopt;
}
