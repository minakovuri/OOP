#pragma once
#include <string>
#include <optional>

bool IsNumber(const std::string& str);
std::optional<unsigned int> GetUpperBound(int argc, char* argv[]);