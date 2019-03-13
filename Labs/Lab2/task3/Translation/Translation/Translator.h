#pragma once
#include <optional>
#include <string>
#include <vector>

#include "Dictionary.h"

using VectorOfWords = std::vector<std::string>;

std::optional<VectorOfWords> Translate(const std::string& engWord, const Dictionary& dictionary);
void AddTranslation(const std::string& engWord, const std::string& rusWord, Dictionary& dictionary);
