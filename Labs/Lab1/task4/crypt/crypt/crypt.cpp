
#include "pch.h"
#include "InputParser.h"
#include "Transformer.h"

int main(int argc, char* argv[])
{
	InputParameters inputParameters;

	try
	{
		inputParameters = GetInputParameters(argc, argv);
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		return 1;
	}

	TransformInputFile(inputParameters);

	return 0;
}
