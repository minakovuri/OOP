#include "pch.h"
#include <algorithm>
#include <cctype>
#include "InputParser.h"

const int MAX_PARAMS_COUNT = 1;

bool IsNumber(const std::string& str)
{
	return std::all_of(str.begin(), str.end(), std::isdigit);
}

std::optional<unsigned long> GetUpperBound(int argc, char* argv[])
{
	if (argc != MAX_PARAMS_COUNT + 1)
	{
		std::cerr << "Incorrect  parameters count" << std::endl;
		return std::nullopt;
	}

	const std::string upperBoundStr = argv[1];

	if (!IsNumber(upperBoundStr))
	{
		std::cerr << "Inpit parameter is not a number" << std::endl;
		return std::nullopt;
	}

	unsigned long upperBound = 0;

	try
	{
		upperBound = atoi(upperBoundStr.c_str());
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return std::nullopt;
	}

	return upperBound;
}
