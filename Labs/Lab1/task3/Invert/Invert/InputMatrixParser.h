#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "MatrixType.h"

using InputFileName = std::string;

InputFileName GetInputFileName(int argc, char* argv[]);
void ReadMatrixFromFile(Matrix3x3, InputFileName&);
