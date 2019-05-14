#include "pch.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

int main()
{
	std::string line;

	while (std::getline(std::cin, line))
	{
		try
		{
			CHttpUrl url(line);
			std::cout << "URL: " << url.GetURL() << std::endl;

			if (url.GetProtocol() == Protocol::HTTP)
			{
				std::cout << "Protocol: http" << std::endl;
			}
			else
			{
				std::cout << "Protocol: https" << std::endl;
			}

			std::cout << "Domain: " << url.GetDomain() << std::endl;
			std::cout << "Port: " << url.GetPort() << std::endl;
			std::cout << "Document: " << url.GetDocument() << std::endl;
		}
		catch (const std::invalid_argument const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
