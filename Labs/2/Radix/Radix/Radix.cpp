#include <iostream>

#include "pch.h"
#include "InputChecker.h"
#include "TypesTranslator.h"

int main(int argc, char* argv[])
{
	/*bool wasError = false;

	CheckParametersCount(argc, wasError);

	if (wasError)
	{
		return 1;
	}

	int sourceNotation = StringToInt(argv[1], 10, wasError);

	CheckInputRadix(sourceNotation, wasError);

	if (wasError)
	{
		return 1;
	}

	int destinationNotation = StringToInt(argv[2], 10, wasError);

	CheckInputRadix(destinationNotation, wasError);

	if (wasError)
	{
		return 1;
	}

	int value = StringToInt(argv[3], sourceNotation, wasError);

	if (wasError)
	{
		return 1;
	}*/

	InputParameters inputParameters;



	std::string stringValue = IntToString(value, destinationNotation);

	std::cout << stringValue << std::endl;

	return 0;
}
