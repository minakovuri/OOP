#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PrimesGenerator.h"

TEST_CASE("Check the size of the resulting set of prime numbers"){
	REQUIRE(GeneratePrimeNumbersSet(0).size() == 0);
	REQUIRE(GeneratePrimeNumbersSet(1).size() == 0);
	REQUIRE(GeneratePrimeNumbersSet(2).size() == 1);
	REQUIRE(GeneratePrimeNumbersSet(3).size() == 2);
	REQUIRE(GeneratePrimeNumbersSet(4).size() == 2);
	REQUIRE(GeneratePrimeNumbersSet(6).size() == 3);
	REQUIRE(GeneratePrimeNumbersSet(10).size() == 4);
};

TEST_CASE("Obtain sets of prime numbers and compare with the reference")
{
	{
		PrimeSet emptySet = {};
		REQUIRE(GeneratePrimeNumbersSet(0) == emptySet);
		REQUIRE(GeneratePrimeNumbersSet(1) == emptySet);
	}

	REQUIRE(GeneratePrimeNumbersSet(2) == PrimeSet{ 2 });
	REQUIRE(GeneratePrimeNumbersSet(3) == PrimeSet{ 2, 3 });
	REQUIRE(GeneratePrimeNumbersSet(4) == PrimeSet{ 2, 3 });
	REQUIRE(GeneratePrimeNumbersSet(6) == PrimeSet{ 2, 3, 5 });
	REQUIRE(GeneratePrimeNumbersSet(10) == PrimeSet{ 2, 3, 5, 7 });
};

#ifdef NDEBUG
TEST_CASE("Test GeneratePrimeNumbersSet() with large number")
{
	PrimeSet primeSet;
	CHECK_NOTHROW(primeSet = GeneratePrimeNumbersSet(100'000'000));
	REQUIRE(primeSet.size() == 5'761'455);
};
#endif
