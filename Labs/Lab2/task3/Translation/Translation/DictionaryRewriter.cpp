#include "pch.h"
#include "DictionaryRewriter.h"
#include <fstream>
#include <iostream>

void WriteDictionaryToFile(const std::string& fileName, const Dictionary& dictionary)
{
	using namespace std;

	ofstream file(fileName);

	if (!file.is_open())
	{
		throw invalid_argument("Cannot open/create file: '" + fileName + "'");
	}

	for (auto it = dictionary.begin(); it != dictionary.end(); it++)
	{
		file << (it->first) << " " << (it->second) << endl;
	}
}
