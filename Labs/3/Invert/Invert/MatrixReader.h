#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "MatrixParams.h"

void ReadMatrixFromFile(int matrix[][MATRIX_SIZE], std::string matrixFileName);
