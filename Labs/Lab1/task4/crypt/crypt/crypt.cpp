
#include "pch.h"
#include "InputParser.h"
#include "Handler.h"

int main(int argc, char* argv[])
{
	InputParameters inputParameters;

	try
	{
		inputParameters = GetInputParameters(argc, argv);
	}
	catch (const std::exception&)
	{
		return 1;
	}

	HandleFiles(inputParameters);

	return 0;
}
