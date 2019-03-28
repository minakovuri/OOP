#include "pch.h"
#include <algorithm>
#include <cctype>
#include "InputParser.h"

const int MAX_PARAMS_COUNT = 1;
const int MAX_UPPER_BOUND = 100'000'000;

bool IsNumber(const std::string& str)
{
	return std::all_of(str.begin(), str.end(), std::isdigit);
}

std::optional<unsigned int> GetUpperBound(int argc, char* argv[])
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

	unsigned int upperBound = 0;

	try
	{
		upperBound = stoi(upperBoundStr);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return std::nullopt;
	}

	if (upperBound > MAX_UPPER_BOUND)
	{
		std::cerr << "Inpit parameter is more then 100'000'000" << std::endl;
		return std::nullopt;
	}

	return upperBound;
}
