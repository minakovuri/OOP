#include "pch.h"
#include "Translator.h"

#include <algorithm>

std::optional<VectorOfWords> Translate(const std::string& engWord, const Dictionary& dictionary)
{
	std::string engWordCopy = engWord;
	std::transform(engWordCopy.begin(), engWordCopy.end(), engWordCopy.begin(), ::tolower);

	auto result = dictionary.equal_range(engWordCopy);

	if (result.first == result.second)
	{
		return std::nullopt;
	}

	VectorOfWords words;

	for (auto it = result.first; it != result.second; it++)
	{
		words.push_back(it->second);
	}

	return words;
}

void AddTranslation(const std::string& engWord, const std::string& rusWord, Dictionary& dictionary)
{
	using namespace std;

	dictionary.insert(pair<string, string>(engWord, rusWord));
}
