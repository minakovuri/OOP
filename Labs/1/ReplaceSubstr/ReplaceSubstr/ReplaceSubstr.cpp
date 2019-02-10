#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // манипуляторы ввода/вывода

int main(int argc, char *argv[])
{
	// если программа запустится с неправильным кол-вом аргументов - ненулевой код возврата
	if (argc < 5) 
	{
		std::cerr << "Not anougth arguments!" << std::endl;
		return 1;
	}

	// инициализация и открытие входного файла (по умолчанию в режиме чтения)
	std::string inputFileName = argv[1];
	std::ifstream inputFile(inputFileName);
	
	// обработка некорректного открытия входного файла
	if (!inputFile.is_open())
	{
		std::cerr << "Cannot open " << inputFileName << " file!" << std::endl; 
		return 1;
	}

	// инициализация и открытие выходного файла в режиме записи с предварительной очисткой
	std::string outputFileName = argv[2];
	std::ofstream outputFile(outputFileName, std::ios_base::out | std::ios_base::trunc);

	// обработка некорректного создания или открытия выходного файла
	if (!outputFile.is_open())
	{
		std::cerr << "Cannot open or create " << outputFileName << " file!" << std::endl;
		return 1;
	}

	// инициализация строки поиска
	std::string searchString = argv[3];

	// инициализация строки-заменителя
	std::string replaceString = argv[4];

	// построчная обработка файла
	std::string currentLine;
	while (std::getline(inputFile, currentLine))
	{
		if (!searchString.empty())
		{
			for (size_t position = 0;; position += replaceString.length())
			{
				position = currentLine.find(searchString, position);

				if (position == std::string::npos)
				{
					break;
				}

				currentLine.erase(position, searchString.length());
				currentLine.insert(position, replaceString);
			}
		}

		outputFile << currentLine;
	}

	// закрытие входного и выходного файлов
	inputFile.close();
	outputFile.close();

	return 0;
}
