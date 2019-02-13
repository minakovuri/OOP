#pragma once

#include <iostream>
#include <string>

int StringToInt(const std::string& str, int radix, bool& wasError);
std::string IntToString(int n, int radix, bool& wasError);
