#pragma once
#include "Protocol.h"

Protocol ParseProtocol(std::string const& url);
std::string ParseDomain(std::string const& url);
unsigned short ParsePort(std::string const& url);
std::string ParseDocument(std::string const& url);
