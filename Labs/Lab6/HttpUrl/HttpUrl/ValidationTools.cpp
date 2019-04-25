#include "pch.h"
#include "ValidationTools.h"

bool IsCharAllowed(char const ch)
{
	if (isdigit(ch) || isalpha(ch) || (ch == '-') || (ch == '.') || (ch == '_') || (ch == '~'))
	{
		return true;
	}

	return false;
}

void ValidateDomain(std::string const& domain)
{
	for (char const& ch : domain)
	{
		if (!IsCharAllowed(ch))
		{
			throw std::invalid_argument("Invalid URL domain name");
		}
	}
}

void ValidateDocument(std::string const& document)
{
	std::string doc(document);

	if (doc[0] == '/')
	{
		doc.erase(0, 1);
	}

	for (char const& ch : doc)
	{
		if (!IsCharAllowed(ch) && (ch != '/'))
		{
			throw std::invalid_argument("Invalid URL document name");
		}
	}
}