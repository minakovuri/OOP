#pragma once

#include <iostream>
#include "InputFormat.h"

InputParameters GetInputParameters(int argc, char* argv[]);
ExecutionMode GetExecutionMode(const std::string&);
void OpenFilesSafety(InputParameters& inputParameters, const std::string& inputFileName, const std::string& outputFileName);
Key GetKey(const std::string&);