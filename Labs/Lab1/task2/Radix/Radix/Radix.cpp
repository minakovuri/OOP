#include <iostream>

#include "pch.h"
#include "InputParser.h"
#include "TypesTranslator.h"

int main(int argc, char* argv[])
{
	std::optional<InputParameters> optionalInputParameters = GetInputParameters(argc, argv);

	if (!optionalInputParameters)
	{
		return 1;
	}

	InputParameters inputParameters = *optionalInputParameters;

	std::string stringValue = IntToString(inputParameters.value, inputParameters.destinationNotation);
	std::cout << stringValue << std::endl;

	return 0;
}
