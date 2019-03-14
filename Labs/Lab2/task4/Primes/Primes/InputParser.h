#pragma once
#include <string>
#include <optional>

bool IsNumber(const std::string& str);
std::optional<unsigned long> GetUpperBound(int argc, char* argv[]);