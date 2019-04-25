#pragma once
#include "Protocol.h"

class CHttpUrl final
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = Protocol::HTTP);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);

	~CHttpUrl();

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

private:
	void ParseUrl(std::string const& url);

	Protocol m_protocol;
	std::string m_domain;
	std::string m_document;
	unsigned short m_port;
};
