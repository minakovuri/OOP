#include <iostream>

#include "pch.h"
#include "MatrixType.h"
#include "MatrixHandler.h"
#include "MatrixParams.h"
#include "InputMatrixParser.h"

int main(int argc, char* argv[])
{
	Matrix3x3 matrix;

	try
	{
		InputFileName inputFileName = GetInputFileName(argc, argv);
		ReadMatrixFromFile(matrix, inputFileName);
	}
	catch (const std::exception&)
	{
		std::cerr << "Invalid parameters " << std::endl;
		return 1;
	}

	float determinant = GetDeterminant(matrix);

	Matrix3x3 inverseMatrix;

	bool invertSuccess = InvertMatrix(matrix, inverseMatrix, determinant);

	if (!invertSuccess)
	{
		std::cout << "Cannot invert matrix " << std::endl;
		return 1;
	}

	WriteMatrix(inverseMatrix);

	return 0;
}
