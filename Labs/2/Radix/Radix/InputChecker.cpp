#include "pch.h"
#include "InputChecker.h"

const int CORRECT_ARGUMENTS_COUNT = 4;
const int MIN_RADIX = 2;
const int MAX_RADIX = 36;

std::optional<InputParameters> GetInputParameters(int argc, char* argv[])
{
	InputParameters inputParameters;

	bool wasError = false;

	CheckParametersCount(argc, wasError);

	if (wasError)
	{
		return std::nullopt;
	}

	inputParameters.sourceNotation = StringToInt(argv[1], 10, wasError);
	CheckInputRadix(inputParameters.sourceNotation, wasError);

	if (wasError)
	{
		return std::nullopt;
	}

	inputParameters.destinationNotation = StringToInt(argv[2], 10, wasError);
	CheckInputRadix(inputParameters.destinationNotation, wasError);

	if (wasError)
	{
		return std::nullopt;
	}

	inputParameters.value = StringToInt(argv[3], inputParameters.sourceNotation, wasError);

	if (wasError)
	{
		return std::nullopt;
	}

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
