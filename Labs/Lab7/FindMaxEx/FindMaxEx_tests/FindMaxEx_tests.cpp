#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../FindMaxEx/FindMax.h"
#include "Athletes.h"

void VerifyAthlete(const SAthlete& lhs, const SAthlete& rhs)
{
	CHECK(lhs.fullName == rhs.fullName);
	CHECK(lhs.height == rhs.height);
	CHECK(lhs.height == rhs.height);
}

SAthlete UsainBolt = { "Usain Bolt", 195.0, 94.0 };
SAthlete MohamedSalah = { "Mohamed Salah", 175.50, 75.4 };
SAthlete OleBjorndalen = { "Ole Bjorndalen", 179, 66 };
SAthlete MuhammadAli = { "Muhammad Ali", 191.30, 107 };

std::vector<SAthlete> athletes = {
	UsainBolt,
	MohamedSalah,
	OleBjorndalen,
	MuhammadAli
};

TEST_CASE("Find athlete with max height")
{
	SAthlete highestAlthelete;

	CHECK(FindMax(athletes, highestAlthelete, IsHeigher));

	VerifyAthlete(highestAlthelete, UsainBolt);
}

TEST_CASE("Find athlete with max weight")
{
	SAthlete maxWeightAlthelete;

	CHECK(FindMax(athletes, maxWeightAlthelete, IsMoreWeight));

	VerifyAthlete(maxWeightAlthelete, MuhammadAli);
}

TEST_CASE("Test FindMax function with empty array")
{
	float maxNum = NAN;
	CHECK(!FindMax({}, maxNum, [](const auto& lhi, const auto& rhi) { 
		return (lhi < rhi); 
	}));
	CHECK(isnan(maxNum));
}

TEST_CASE("Exception check FindMax function with empty last parameter")
{
	float maxNum = NAN;
	CHECK_NOTHROW(FindMax({}, maxNum));
	CHECK(isnan(maxNum));
}

TEST_CASE("Find max element in integers array by FindMax function without third parameter")
{
	int maxNum = 0;
	CHECK(FindMax({ -1, 1, 0, 15, 5 }, maxNum));
	CHECK(maxNum == 15);
}

TEST_CASE("Find min element in chars array by FindMax function")
{
	char minCh = '#';
	CHECK(FindMax({'a', 'b', 'c', 'e', 'd'}, minCh, [](const auto& lhc, const auto& rhc) {
		return (lhc > rhc);
	}));
	CHECK(minCh == 'a');
}
