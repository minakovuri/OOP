#pragma once

#include <iostream>
#include <string>

const std::string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int StringToInt(const std::string& str, int radix, bool& wasError);
std::string IntToString(int n, int radix);
