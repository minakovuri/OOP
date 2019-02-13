#include <iostream>

#include "pch.h"
#include "InputChecker.h"
#include "TypesTranslator.h"

int main(int argc, char* argv[])
{
	bool wasError = false;

	checkParametersCount(argc, wasError);

	if (wasError)
	{
		return 1;
	}

	int sourceNotation = StringToInt(argv[1], 10, wasError);

	checkInputRadix(sourceNotation, wasError);

	if (wasError)
	{
		return 1;
	}

	int destinationNotation = StringToInt(argv[2], 10, wasError);

	checkInputRadix(destinationNotation, wasError);

	if (wasError)
	{
		return 1;
	}

	int decimalValue = StringToInt(argv[3], sourceNotation, wasError);

	if (wasError)
	{
		return 1;
	}

	std::string stringValue = IntToString(decimalValue, destinationNotation, wasError);

	std::cout << stringValue << std::endl;

	return 0;
}
