#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "MatrixType.h"

float GetDeterminant(Matrix3x3 matrix);
float GetAdditionMatrixElement(Matrix3x3 matrix, int i, int j);
bool InvertMatrix(Matrix3x3 matrix, Matrix3x3 invertMatrix, float determinant);
void WriteMatrix(Matrix3x3 invertMatrix);
