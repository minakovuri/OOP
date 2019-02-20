#include "pch.h"
#include "TypesTranslator.h"

int StringToInt(const std::string& str, int radix, bool& wasError)
{
	try
	{
		int num = 0;

		int digit = 0;
		std::string availableDigits = DIGITS.substr(0, radix);

		bool isNumNegative = (str[0] == '-');

		// если число отрицательное, то перебор цифр начинаем со второго символа, если положительное - с первого
		for (int i = isNumNegative; i < str.length(); i++)
		{
			digit = availableDigits.find(str[i]);

			if (digit == std::string::npos)
			{
				throw std::invalid_argument("Invalud argument");
			}

			if ((isNumNegative) && ((-1) * num < (-1) * (INT_MIN - digit) / radix))
			{
				std::cout << "Out of range" << std::endl;
				throw std::out_of_range("Out of range!");
			}

			if ((!isNumNegative) && (num > (INT_MAX - digit) / radix))
			{
				std::cout << "Out of range" << std::endl;
				throw std::out_of_range("Out of range!");
			}

			num = num * radix + digit;
		}

		if (isNumNegative)
		{
			num = num * (-1);
		}

		return num;
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
}

std::string IntToString(int n, int radix)
{
	char charsArray[1024] = "";

	_itoa_s(n, charsArray, radix);

	return (std::string)charsArray;
}
