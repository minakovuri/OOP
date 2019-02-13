#include "pch.h"
#include "InputChecker.h"

void checkParametersCount(int argc, bool& wasError)
{
	if (argc < 4)
	{
		std::cerr << "Not anougth arguments!" << std::endl;
		wasError = true;
	}
}

void checkInputRadix(int radix, bool& wasError)
{
	if ((radix < 2) || (radix > 36))
	{
		std::cerr << "Incorrect radix (from 2 to 36 required): " << radix << std::endl;
		wasError = true;
	}
}
