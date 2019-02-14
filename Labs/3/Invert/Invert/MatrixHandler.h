#pragma once

#include <iostream>
#include <string>

#include "MatrixParams.h"

float getDeterminant(int matrix[][MATRIX_SIZE]);
void MakeInvertMatrix(int matrix[][MATRIX_SIZE], float invertMatrix[][MATRIX_SIZE], float determinant);
void WriteInvertMatrix(float invertMatrix[][MATRIX_SIZE]);
