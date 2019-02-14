#include "pch.h"
#include "MatrixReader.h"

void ReadMatrixFromFile(int matrix[][MATRIX_SIZE], std::string matrixFileName)
{
	std::ifstream matrixFile(matrixFileName);

	if (!matrixFile.is_open())
	{
		std::cerr << "Cannot open " << matrixFileName << " file!" << std::endl;
		throw std::invalid_argument("Cannot open file");
	}

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			matrixFile >> matrix[i][j];
		}
	}
}
