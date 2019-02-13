#include <iostream>

#include "pch.h"
#include "InputChecker.h"
#include "TypesTranslator.h"

int main(int argc, char* argv[])
{
	// инициализция флага ошибки
	bool wasError = false;

	// проверка кол-ва аргументов программы
	checkParametersCount(argc, wasError);

	if (wasError)
	{
		return 1;
	}

	// инициализация исходной системы счистления
	int sourceNotation = StringToInt(argv[1], 10, wasError);

	// проверка системы счисления (требуются числа от 2 до 36)
	checkInputRadix(sourceNotation, wasError);

	if (wasError)
	{
		return 1;
	}

	// инициализация выходной системы счистления
	int destinationNotation = StringToInt(argv[2], 10, wasError);

	// проверка системы счисления (требуются числа от 2 до 36)
	checkInputRadix(destinationNotation, wasError);

	if (wasError)
	{
		return 1;
	}

	// инициализация значения
	int decimalValue = StringToInt(argv[3], sourceNotation, wasError);

	if (wasError)
	{
		return 1;
	}

	std::string stringValue = IntToString(decimalValue, destinationNotation, wasError);

	std::cout << stringValue << std::endl;

	return 0;
}
