#include "pch.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

#include "ParsingTools.h"
#include "ValidationTools.h"

CHttpUrl::CHttpUrl(std::string const& url)
{
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
	: m_protocol(protocol)
{
	ValidateDomain(domain);
	ValidateDocument(document);

	m_domain = domain;
	m_document = document;
	m_port = (protocol == Protocol::HTTP) ? DEFAULT_HTTP_PORT : DEFAULT_HTTPS_PORT;
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port) 
	: m_protocol(protocol)
	, m_port(port)
{
	ValidateDomain(domain);
	ValidateDocument(document);

	m_domain = domain;
	m_document = document;
}

CHttpUrl::~CHttpUrl()
{
}

void CHttpUrl::ParseUrl(std::string const& url)
{
	m_domain = ParseDomain(url);

	auto const protocolDelimeter = url.find("://");

	if (protocolDelimeter == std::string::npos)
	{
		m_protocol = Protocol::HTTP;

		auto const portDelimeter = url.find(':');

		if (portDelimeter == std::string::npos)
		{
			m_port = (m_protocol == Protocol::HTTP) ? DEFAULT_HTTP_PORT : DEFAULT_HTTPS_PORT;
		}
		else
		{
			m_port = ParsePort(url);
		}
	}
	else
	{
		m_protocol = ParseProtocol(url);

		auto const portDelimeter = url.find(':', protocolDelimeter + 3);

		if (portDelimeter == std::string::npos)
		{
			m_port = (m_protocol == Protocol::HTTP) ? DEFAULT_HTTP_PORT : DEFAULT_HTTPS_PORT;
		}
		else
		{
			m_port = ParsePort(url);
		}
	}

	m_document = ParseDocument(url);
}

std::string CHttpUrl::GetURL() const
{
	std::string url;

	if (m_protocol == Protocol::HTTP)
	{
		url += "http";
	}
	else
	{
		url += "https";
	}

	url += "://";

	url += m_domain;

	if ((m_port != DEFAULT_HTTP_PORT) && (m_port != DEFAULT_HTTPS_PORT))
	{
		url += ':' + std::to_string(m_port);
	}

	url += m_document;

	return url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}
