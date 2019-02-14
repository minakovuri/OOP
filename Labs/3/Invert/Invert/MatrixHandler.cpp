#include "pch.h"
#include "MatrixHandler.h"

float getDeterminant(int matrix[][MATRIX_SIZE])
{
	return (float)(matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[2][0] * matrix[0][1] * matrix[1][2]) + (matrix[0][2] * matrix[1][0] * matrix[2][1])
		- (matrix[2][0] * matrix[1][1] * matrix[0][2]) - (matrix[2][2] * matrix[1][0] * matrix[0][1]) - (matrix[0][0] * matrix[2][1] * matrix[1][2]);
}

void InvertMatrix(int matrix[][MATRIX_SIZE], float invertMatrix[][MATRIX_SIZE], float determinant)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			invertMatrix[i][j] = ((matrix[(j + 1) % 3][(i + 1) % 3] * matrix[(j + 2) % 3][(i + 2) % 3]) - (matrix[(j + 1) % 3][(i + 2) % 3] * matrix[(j + 2) % 3][(i + 1) % 3])) / determinant;
		}
	}
}

void WriteInvertMatrix(float invertMatrix[][MATRIX_SIZE])
{
	std::string stringFloat;

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			stringFloat = std::to_string(invertMatrix[i][j]);

			size_t dotPosition = stringFloat.find(".");
			std::string fullPart = stringFloat.substr(0, dotPosition);
			std::string fractionPart = stringFloat.substr(dotPosition + 1, 3);

			std::cout << fullPart << "." << fractionPart << " ";
		}

		std::cout << std::endl;
	}
}
