#include "pch.h"
#include "PrimesGenerator.h"
#include "InputParser.h"
#include "ConsoleWriter.h"

int main(int argc, char* argv[])
{
	std::optional<unsigned long> uppedBound = GetUpperBound(argc, argv);

	if (!uppedBound)
	{
		return 1;
	}

	const auto primes = GeneratePrimeNumbersSet(uppedBound.value());

	DisplayPrimes(primes);

	return 0;
}
