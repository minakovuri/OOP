#include "pch.h"
#include <fstream>
#include <iomanip> // манипуляторы ввода/вывода
#include <iostream>
#include <string>

#include "StringReplacer.h"

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		std::cerr << "Not anougth arguments!" << std::endl;
		return 1;
	}

	std::string inputFileName = argv[1];
	std::ifstream inputFile(inputFileName);

	if (!inputFile.is_open())
	{
		std::cerr << "Cannot open " << inputFileName << " file!" << std::endl;
		return 1;
	}

	std::string outputFileName = argv[2];
	std::ofstream outputFile(outputFileName, std::ios_base::out | std::ios_base::trunc);

	if (!outputFile.is_open())
	{
		std::cerr << "Cannot open or create " << outputFileName << " file!" << std::endl;
		return 1;
	}

	std::string searchString = argv[3];

	std::string replaceString = argv[4];

	std::string currentLine;

	while (std::getline(inputFile, currentLine))
	{
		if (!searchString.empty())
		{
			ReplaceString(searchString, replaceString, currentLine);
		}

		outputFile << currentLine;
	}

	return 0;
}
