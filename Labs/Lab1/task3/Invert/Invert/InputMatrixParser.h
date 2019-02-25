#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "MatrixParams.h"

void GetInputParameters(int[][MATRIX_SIZE], int, char* []);
void ReadMatrixFromFile(int [][MATRIX_SIZE], std::string);
