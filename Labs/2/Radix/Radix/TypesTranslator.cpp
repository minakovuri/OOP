#include "pch.h"
#include "TypesTranslator.h"

int StringToInt(const std::string& str, int radix, bool& wasError)
{
	int num = 0;

	try
	{
		size_t pos = 0;
		num = std::stoi(str, &pos, radix);
		if (str[pos] != '\0')
		{
			throw std::invalid_argument("");
		}
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Entered number is out of int range: " << str << std::endl;
		wasError = true;
	}
	catch (const std::invalid_argument iaex)
	{
		std::cerr << "Invalid argument to parse string from int: " << str << " in base " << radix << std::endl;
		wasError = true;
	}

	return num;
}

std::string IntToString(int n, int radix, bool& wasError)
{
	char charsArray[20] = "";

	try
	{
		_itoa_s(n, charsArray, radix);
	}
	catch (const std::exception&)
	{
		wasError = true;
	}

	return (std::string)charsArray;
}
