#include "pch.h"
#include "InputMatrixParser.h"

void GetInputParameters(int matrix[][MATRIX_SIZE], int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Not anougth arguments!" << std::endl;
		throw std::invalid_argument("Not enough arguments!");
	}

	ReadMatrixFromFile(matrix, argv[1]);
}

void ReadMatrixFromFile(int matrix[][MATRIX_SIZE], std::string matrixFileName)
{
	std::ifstream matrixFile(matrixFileName);

	if (!matrixFile.is_open())
	{
		std::cerr << "Cannot open " << matrixFileName << " file!" << std::endl;
		throw std::invalid_argument("Cannot open file");
	}

	std::string row;
	std::vector<std::vector<int>> inputMatrix;

	while (std::getline(matrixFile, row))
	{
		std::stringstream ss(row);
		int number;
		std::vector<int> inputMatrixRow;

		while (ss >> number)
		{
			inputMatrixRow.push_back(number);
		}

		if (inputMatrixRow.size() != MATRIX_SIZE)
		{
			std::cerr << "Entered matrix hasn't got 3 columns!" << std::endl;
			throw std::invalid_argument("Entered matrix hasn't got 3 columns!");
		}

		inputMatrix.push_back(inputMatrixRow);
	}

	if (inputMatrix.size() != MATRIX_SIZE)
	{
		std::cerr << "Entered matrix hasn't got 3 rows!" << std::endl;
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
