#pragma once

#include <string>
#include <optional>

std::optional<std::string> GetHtmlEntity(const char symbol);
std::optional<char> GetSpecialSymbol(std::string const& htmlEntity);