#include "pch.h"
#include "CUrlParsingError.h"

CUrlParsingError::CUrlParsingError(std::string const& message)
	: std::invalid_argument(message)
{
}

CUrlParsingError::~CUrlParsingError()
{
}
