#include "pch.h"
#include "MatrixParams.h"
#include "InputMatrixParser.h"

InputFileName GetInputFileName(int argc, char* argv[])
{
	if (argc < 2)
	{
		throw std::invalid_argument("Not enough arguments!");
	}

	return argv[1];
}

void ReadMatrixFromFile(Matrix3x3 matrix, InputFileName& matrixFileName)
{
	std::ifstream matrixFile(matrixFileName);

	if (!matrixFile.is_open())
	{
		throw std::invalid_argument("Cannot open file");
	}

	std::string row;
	std::vector<std::vector<float>> inputMatrix;

	while (std::getline(matrixFile, row))
	{
		std::stringstream ss(row);
		float number;
		std::vector<float> inputMatrixRow;

		while (ss >> number)
		{
			inputMatrixRow.push_back(number);
		}

		if (inputMatrixRow.size() != MATRIX_SIZE)
		{
			throw std::invalid_argument("Entered matrix hasn't got 3 columns!");
		}

		inputMatrix.push_back(inputMatrixRow);
	}

	if (inputMatrix.size() != MATRIX_SIZE)
	{
		throw std::invalid_argument("Entered matrix hasn't got 3 rows!");
	}

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			matrix[i][j] = inputMatrix[i][j];
		}
	}
}
