#include <iostream>

#include "pch.h"
#include "MatrixHandler.h"
#include "MatrixParams.h"
#include "InputMatrixParser.h"

int main(int argc, char* argv[])
{
	int matrix[MATRIX_SIZE][MATRIX_SIZE];
	float determinant;

	try
	{
		GetInputParameters(matrix, argc, argv);
		determinant = getDeterminant(matrix);
	}
	catch (const std::exception&)
	{
		return 1;
	}

	float inverseMatrix[MATRIX_SIZE][MATRIX_SIZE];

	InvertMatrix(matrix, inverseMatrix, determinant);

	WriteInvertMatrix(inverseMatrix);

	return 0;
}
