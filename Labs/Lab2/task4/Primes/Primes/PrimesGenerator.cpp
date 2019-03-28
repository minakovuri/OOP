#include "pch.h"
#include "PrimesGenerator.h"

PrimeSet GeneratePrimeNumbersSet(const unsigned int upperBound)
{
	PrimeSet primeSet;

	if (upperBound < 2)
	{
		return primeSet;
	}

	std::vector<bool> primes(upperBound + 1, true);

	primes[0] = primes[1] = false;

	for (unsigned int i = 2; i * i <= upperBound; ++i)
	{
		if (primes[i])
		{
			for (unsigned int j = i * i; j <= upperBound; j += 2 * i)
			{
				primes[j] = false;
			}
		}
	}

	for (unsigned i = 1; i <= upperBound; i += 2)
	{
		if (primes[i])
		{
			primeSet.insert(i);
		}
	}

	return primeSet;
}
