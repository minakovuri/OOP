#include "pch.h"
#include "InputChecker.h"

const int CORRECT_ARGUMENTS_COUNT = 4;
const int MIN_RADIX = 2;
const int MAX_RADIX = 36;

void checkParametersCount(int argc, bool& wasError)
{
	if (argc < CORRECT_ARGUMENTS_COUNT)
	{
		std::cerr << "Not anougth arguments!" << std::endl;
		wasError = true;
	}
}

void checkInputRadix(int radix, bool& wasError)
{
	if ((radix < MIN_RADIX) || (radix > MAX_RADIX))
	{
		std::cerr << "Incorrect radix (from 2 to 36 required): " << radix << std::endl;
		wasError = true;
	}
}
