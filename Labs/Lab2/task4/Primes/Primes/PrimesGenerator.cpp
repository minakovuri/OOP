#include "pch.h"
#include "PrimesGenerator.h"

PrimeSet GeneratePrimeNumbersSet(const unsigned long upperBound)
{
	PrimeSet primeSet;

	if (upperBound < 2)
	{
		return primeSet;
	}

	std::vector<bool> primes(upperBound + 1, true);

	primes[0] = primes[1] = false;

	for (unsigned i = 2; i * i <= upperBound; ++i)
	{
		if (primes[i])
		{
			for (unsigned j = i * i; j <= upperBound; j += 2 * i)
			{
				primes[j] = false;
			}
		}
	}

	primeSet.insert(2);

	for (unsigned i = 3; i <= upperBound; i += 2)
	{
		if (primes[i])
		{
			primeSet.insert(i);
		}
	}

	return primeSet;
}
