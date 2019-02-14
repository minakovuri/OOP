#include <iostream>

#include "pch.h"
#include "MatrixHandler.h"
#include "MatrixParams.h"
#include "MatrixReader.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Not anougth arguments!" << std::endl;
		return 1;
	}

	int matrix[MATRIX_SIZE][MATRIX_SIZE];

	try
	{
		ReadMatrixFromFile(matrix, argv[1]);
	}
	catch (const std::exception&)
	{
		return 1;
	}

	float determinant = getDeterminant(matrix);

	float invertMatrix[MATRIX_SIZE][MATRIX_SIZE];

	MakeInvertMatrix(matrix, invertMatrix, determinant);

	WriteInvertMatrix(invertMatrix);

	return 0;
}
