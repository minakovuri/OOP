#pragma once

#include <string>
#include <optional>

std::optional<std::string> GetHtmlEntity(char symbol);
std::optional<char> GetSpecialSymbol(std::string& htmlEntity);