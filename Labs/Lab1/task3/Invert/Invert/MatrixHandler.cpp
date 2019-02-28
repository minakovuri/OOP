#include "pch.h"
#include "MatrixParams.h"
#include "MatrixHandler.h"

float GetDeterminant(Matrix3x3 matrix)
{
	return (float)(matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[2][0] * matrix[0][1] * matrix[1][2]) + (matrix[0][2] * matrix[1][0] * matrix[2][1])
		- (matrix[2][0] * matrix[1][1] * matrix[0][2]) - (matrix[2][2] * matrix[1][0] * matrix[0][1]) - (matrix[0][0] * matrix[2][1] * matrix[1][2]);
}

float GetAdditionMatrixElement(Matrix3x3 matrix, int i, int j)
{
	if (i == 0)
	{
		if (j == 0)
		{
			return (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) * float(std::pow(-1, i + j + 2));
		}
		else if (j == 1)
		{
			return (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]) * float(std::pow(-1, i + j + 2));
		}
		else
		{
			return (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]) * float(std::pow(-1, i + j + 2));
		}
	}
	else if (i == 1)
	{
		if (j == 0)
		{
			return (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) * float(std::pow(-1, i + j + 2));
		}
		else if (j == 1)
		{
			return (matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2]) * float(std::pow(-1, i + j + 2));
		}
		else
		{
			return (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]) * float(std::pow(-1, i + j + 2));
		}
	}
	else
	{
		if (j == 0)
		{
			return (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]) * float(std::pow(-1, i + j + 2));
		}
		else if (j == 1)
		{
			return (matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]) * float(std::pow(-1, i + j + 2));
		}
		else
		{
			return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]) * float(std::pow(-1, i + j + 2));
		}
	}
}

bool InvertMatrix(Matrix3x3 matrix, Matrix3x3 invertMatrix, float determinant)
{
	if (determinant == 0)
	{
		return false;
	}

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			invertMatrix[i][j] = GetAdditionMatrixElement(matrix, i, j) / determinant;
		}
	}

	return true;
}

void WriteMatrix(Matrix3x3 invertMatrix)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{	
			std::cout << std::fixed;
			std::cout << std::setprecision(3);
			std::cout << invertMatrix[i][j] << ' ';
		}

		std::cout << std::endl;
	}
}
