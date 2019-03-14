#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ProcessVector.h"

TEST_CASE("Run vector through ProcessVector() and check resuls")
{
	{
		VectorOfDoubles numbers = { 2, -1, 5 };
		ProcessVector(numbers);
		VectorOfDoubles required = { 2, 5, 5 };

		REQUIRE(numbers.size() == 3);
		REQUIRE(numbers == required);
	}

	{
		VectorOfDoubles numbers = { 2, -1, 5, 5 };
		ProcessVector(numbers);
		VectorOfDoubles required = { 2, 6, 5, 6 };

		REQUIRE(numbers.size() == 4);
		REQUIRE(numbers != required);
	}
}
