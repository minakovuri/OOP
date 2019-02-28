#include "pch.h"
#include "InputParser.h"
#include "Constants.h"

InputParameters GetInputParameters(int argc, char* argv[])
{
	if (argc < CORRECT_ARGUMENTS_COUNT)
	{
		std::cerr << "Not enougth arguments!" << std::endl;
		throw std::invalid_argument("Not enougth arguments");
	}

	InputParameters inputParameters;
	inputParameters.mode = GetExecutionMode(argv[1]);
	OpenFilesSafety(inputParameters, argv[2], argv[3]);
	inputParameters.key = GetKey(argv[4]);

	return inputParameters;
}

ExecutionMode GetExecutionMode(const std::string& modeName)
{
	std::string lowerCaseModeName = "";

	for (size_t i = 0; i < modeName.length(); i++)
	{
		lowerCaseModeName += tolower(modeName[i]);
	}

	if (lowerCaseModeName == CRYPT_MODE_NAME)
	{
		return CRYPT;
	}
	else if (lowerCaseModeName == DECRYPT_MODE_NAME)
	{
		return DECRYPT;
	}
	else
	{
		std::cerr << "Invalid execution mode: " << modeName << std::endl;
		throw std::invalid_argument("Invalid execution mode");
	}
}

void OpenFilesSafety(InputParameters& inputParameters, const std::string& inputFileName, const std::string& outputFileName)
{
	inputParameters.inputFile.open(inputFileName, std::ios::binary);

	if (!inputParameters.inputFile.is_open())
	{
		std::cerr << "Cannot open input file: " << inputFileName << std::endl;
		throw std::invalid_argument("Cannot open input file");
	}

	inputParameters.outputFile.open(outputFileName, std::ios::binary);

	if (!inputParameters.outputFile.is_open())
	{
		std::cerr << "Cannot open/create output file: " << inputFileName << std::endl;
		throw std::invalid_argument("Cannot open/create output file");
	}
}

Key GetKey(const std::string& keyString)
{
	for (const char digit : keyString)
	{
		if (!isdigit(digit))
		{
			std::cerr << "Invalid key parameter: " << keyString << std::endl;
			throw std::invalid_argument("Invalid key parameter");
		}
	}

	unsigned int keyInt = std::stoi(keyString);

	if (keyInt > MAX_KEY_VALUE)
	{
		std::cerr << "Invalid key parameter: " << keyString << std::endl;
		throw std::invalid_argument("Invalid key parameter");
	}

	return Key(keyInt);
}