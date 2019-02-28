#pragma once

#include <fstream>

using Key = unsigned char;

enum ExecutionMode
{
	CRYPT,
	DECRYPT
};

struct InputParameters
{
	ExecutionMode mode;
	std::ifstream inputFile;
	std::ofstream outputFile;
	Key key;
};