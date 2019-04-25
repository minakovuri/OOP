#include "pch.h"
#include "ParsingTools.h"
#include "CUrlParsingError.h"

#include "ValidationTools.h"

Protocol ParseProtocol(std::string const& url)
{
	auto const end = url.find("://");

	auto protocol = url.substr(0, end);

	std::transform(protocol.begin(), protocol.end(), protocol.begin(), ::tolower);

	if (protocol == "http")
	{
		return Protocol::HTTP;
	}
	else if (protocol == "https")
	{
		return Protocol::HTTPS;
	}
	else
	{
		throw CUrlParsingError("invalid protocol.");
	}
}

std::string ParseDomain(std::string const& url)
{
	auto start = url.find("://");

	if (start == std::string::npos)
	{
		start = 0;
	}
	else
	{
		start += 3;
	}

	auto const end = url.find_first_of("/:", start);
	auto const domain = url.substr(start, (end - start));

	if (domain.empty())
	{
		throw CUrlParsingError("missing domain.");
	}

	try
	{
		ValidateDomain(domain);
	}
	catch (const std::exception&)
	{
		throw CUrlParsingError("invalid domain.");
	}

	return domain;
}

unsigned short ParsePort(std::string const& url)
{
	auto const start = url.find_last_of(':');
	auto const end = url.find('/', start + 1);

	auto port = std::stoi(url.substr(start + 1, (end - start)));

	if ((port < 0) || (port > USHRT_MAX))
	{
		throw CUrlParsingError("invalid port.");
	}

	return port;
}

std::string ParseDocument(std::string const& url)
{
	auto copyUrl(url);

	auto const protocolDelimeter = copyUrl.find("://");

	if (protocolDelimeter != std::string::npos)
	{
		copyUrl.erase(0, protocolDelimeter + 3);
	}

	auto const start = copyUrl.find_first_of('/');

	if (start == std::string::npos)
	{
		return "/";
	}
	else
	{
		if (copyUrl[0] != '/')
		{
			copyUrl = '/' + copyUrl;
		}

		auto const document = copyUrl.substr(start + 1);

		try
		{
			ValidateDocument(document);
		}
		catch (const std::exception&)
		{
			throw CUrlParsingError("invalid document.");
		}

		return document;
	}
}