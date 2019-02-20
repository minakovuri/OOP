#pragma once

#include <iostream>
#include <optional>
#include "TypesTranslator.h"

struct InputParameters
{
	int sourceNotation;
	int destinationNotation;
	int value;
};

std::optional<InputParameters> GetInputParameters(int argc, char* argv[]);

void CheckParametersCount(int argc, bool& wasError);
void CheckInputRadix(int radix, bool& wasError);
