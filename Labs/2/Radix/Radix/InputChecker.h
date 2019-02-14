#pragma once

#include <iostream>
#include "TypesTranslator.h"

struct InputParameters
{
	int sourceNotation;
	int destinationNotation;
	int value;
	bool wasError;
};

InputParameters GetInputParameters(int argc, char* argv[]);

void CheckParametersCount(int argc, bool& wasError);
void CheckInputRadix(int radix, bool& wasError);
