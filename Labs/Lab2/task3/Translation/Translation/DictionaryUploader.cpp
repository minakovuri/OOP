#include "pch.h"
#include "DictionaryUploader.h"
#include <fstream>
#include <iostream>

void UploadDictionaryFromFile(const std::string& fileName, Dictionary& dictionary)
{
	using namespace std;

	ifstream file(fileName);

	if (!file.is_open())
	{
		throw invalid_argument("Cannot open file: '" + fileName + "'");
	}

	string engWord, rusWord;

	while (file >> engWord >> rusWord)
	{
		auto ret = dictionary.insert(pair<string, string>(engWord, rusWord));
	}
}
