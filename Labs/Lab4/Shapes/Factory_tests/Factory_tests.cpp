#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../Shapes/CFactory.h"

#define M_PI 3.141592653589793238463

bool IsEqual(const double a, const double b)
{
	return std::abs(a - b) < FLT_EPSILON;
}

TEST_CASE("Create line segment with factory, check parameters")
{
	VectorOfStrings params{ "0.0", "0.0", "5.6", "4.63", "0x000000" };

	ShapePtr lineSegment = CFactory::CreateLineSegment(params);

	CHECK(IsEqual(lineSegment->GetArea(), 0));

	CHECK(IsEqual(lineSegment->GetPerimeter(), 0));

	CHECK(lineSegment->GetOutlineColor() == 0x000000);
}

TEST_CASE("Try to create line segment with not enough parameters")
{
	VectorOfStrings params{ "0.0", "0.0", "5.6", "4.63" };

	CHECK_THROWS_AS(CFactory::CreateLineSegment(params), std::invalid_argument);
}

TEST_CASE("Create triangle with factory, check parameters")
{
	VectorOfStrings params{ "0.0", "0.0", "2.0", "0.0", "2.0", "2.0", "FF0000", "FF0000" };

	ShapePtr tringle = CFactory::CreateTriangle(params);

	CHECK(IsEqual(tringle->GetArea(), 2.0));

	CHECK(IsEqual(tringle->GetPerimeter(), 2 + 2 + 2 * sqrt(2)));

	CHECK(tringle->GetOutlineColor() == 0xFF0000);
}

TEST_CASE("Try to create triangle with not enough parameters")
{
	VectorOfStrings params{ "0.0", "0.0", "2.0", "0.0", "2.0", "2.0" };

	CHECK_THROWS_AS(CFactory::CreateTriangle(params), std::invalid_argument);
}

TEST_CASE("Create rectangle with factory, check parameters")
{
	VectorOfStrings params{ "2.0", "5.0", "7.0", "3.0", "000000", "FF0000" };

	ShapePtr rectangle = CFactory::CreateRectangle(params);

	CHECK(IsEqual(rectangle->GetArea(), 2 * 5));

	CHECK(IsEqual(rectangle->GetPerimeter(), 2 * 2 + 2 * 5));

	CHECK(rectangle->GetOutlineColor() == 0x000000);
}

TEST_CASE("Try to create rectangle with not enough parameters")
{
	VectorOfStrings params{ "2.0", "5.0", "000000", "FF0000" };

	CHECK_THROWS_AS(CFactory::CreateRectangle(params), std::invalid_argument);
}

TEST_CASE("Create circle with factory, check parameters")
{
	VectorOfStrings params{ "0.0", "0.0", "10.0", "0000FF", "000000" };

	ShapePtr circle = CFactory::CreateCircle(params);

	CHECK(IsEqual(circle->GetArea(), M_PI * 10 * 10));

	CHECK(IsEqual(circle->GetPerimeter(), 2 * M_PI * 10));

	CHECK(circle->GetOutlineColor() == 0x0000ff);
}

TEST_CASE("Try to create circle with not enough parameters")
{
	VectorOfStrings params{ "2.0", "5.0", "000000", "FF0000" };

	CHECK_THROWS_AS(CFactory::CreateCircle(params), std::invalid_argument);
}
