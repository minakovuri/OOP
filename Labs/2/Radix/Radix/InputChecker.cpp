#include "pch.h"
#include "InputChecker.h"

const int CORRECT_ARGUMENTS_COUNT = 4;
const int MIN_RADIX = 2;
const int MAX_RADIX = 36;

Inpu GetInputParameters(int argc, char* argv[])
{
	InputParameters inputParameters;

	inputParameters.sourceNotation = 0;
	inputParameters.destinationNotation = 0;
	inputParameters.value = 0;
	inputParameters.wasError = false;

	bool wasError = false;

	CheckParametersCount(argc, wasError);

	if (wasError)
	{
		return inputParameters;
	}

	int sourceNotation = StringToInt(argv[1], 10, wasError);

	if (wasError)
	{
		inputParameters.wasError = true;
		return inputParameters;
	}

	CheckInputRadix(sourceNotation, wasError);

	if (wasError)
	{
		inputParameters.wasError = true;
		return inputParameters;
	}

	inputParameters.sourceNotation = sourceNotation;

	int destinationNotation = StringToInt(argv[2], 10, wasError);

	if (wasError)
	{
		inputParameters.wasError = true;
		return inputParameters;
	}

	CheckInputRadix(destinationNotation, wasError);

	if (wasError)
	{
		inputParameters.wasError = true;
		return inputParameters;
	}

	inputParameters.destinationNotation = destinationNotation;

	int value = StringToInt(argv[3], sourceNotation, wasError);

	if (wasError)
	{
		inputParameters.wasError = true;
		return inputParameters;
	}

	inputParameters.value = value;
	inputParameters.wasError = false;

	return inputParameters;
}

void CheckParametersCount(int argc, bool& wasError)
{
	if (argc < CORRECT_ARGUMENTS_COUNT)
	{
		std::cerr << "Not anougth arguments!" << std::endl;
		wasError = true;
	}
}

void CheckInputRadix(int radix, bool& wasError)
{
	if ((radix < MIN_RADIX) || (radix > MAX_RADIX))
	{
		std::cerr << "Incorrect radix (from 2 to 36 required): " << radix << std::endl;
		wasError = true;
	}
}
