#include "pch.h"
#include "ConsoleWriter.h"

void DisplayPrimes(const PrimeSet& primeSet)
{
	for (auto it = primeSet.cbegin(); it != primeSet.cend(); ++it)
	{
		std::cout << *it << ' ';
	}
}