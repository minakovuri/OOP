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

			// если текущей цифры нет в заданной системе счисления, то выдать ошибку
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

std::string IntToString(int num, int radix)
{
	if (radix == 10)
	{
		return std::to_string(num);
	}

	// будем добавлять к строке по одной цифре в нужной системе счисления
	std::string str = "";
	char digit;

	bool isNegative = false;
	if (num < 0)
	{
		isNegative = true;
		num *= -1;
	}

	// будем делить заданное число на основание системы и прибовлять цифры, пока не получим 0 
	while (true)
	{
		digit = DIGITS[num % radix];

		str += digit;
		num /= radix;

		if (num == 0)
		{
			break;
		}
	}

	if (isNegative)
	{
		str += '-';
	}

	// реверсируем строку, т.к. мы вписывали цифры и знак в обратном порядке
	std::reverse(str.begin(), str.end());

	return str;
}
