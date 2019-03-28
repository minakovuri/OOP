#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../Shapes/CLineSegment.h"
#include "../Shapes/CPoint.h"
#include "../Shapes/CTriangle.h"

const uint32_t BLACK_COLOR = 0x000000;
const uint32_t RED_COLOR = 0xff0000;

bool IsEqual(const double a, const double b)
{
	return fabs(a - b) < FLT_EPSILON;
}

TEST_CASE("Test CPoint class instance creation")
{
	CPoint point(10.2, 5.6);

	CHECK(IsEqual(point.GetCoordX(), 10.2));
	CHECK(IsEqual(point.GetCoordY(), 5.6));
}

TEST_CASE("Test CLineSegment class instance creation")
{
	CPoint startPoint(0, 0);
	CPoint endPoint(45.5, -23.7);

	CLineSegment lineSegment(startPoint, endPoint, BLACK_COLOR);

	CHECK(IsEqual(lineSegment.GetStartPoint().GetCoordX(), 0));
	CHECK(IsEqual(lineSegment.GetStartPoint().GetCoordY(), 0));

	CHECK(IsEqual(lineSegment.GetEndPoint().GetCoordX(), 45.5));
	CHECK(IsEqual(lineSegment.GetEndPoint().GetCoordY(), -23.7));

	CHECK(lineSegment.GetOutlineColor() == BLACK_COLOR);

	CHECK(IsEqual(lineSegment.GetArea(), 0));

	CHECK(IsEqual(lineSegment.GetPerimeter(), 0));
};

TEST_CASE("Test CTriangle class instance creation")
{
	CPoint vertex1(0, 0);
	CPoint vertex2(3.0, 0);
	CPoint vertex3(3.0, 3.0);

	CTriangle triangle(vertex1, vertex2, vertex3, BLACK_COLOR, RED_COLOR);

	CHECK(IsEqual(triangle.GetVertex1().GetCoordX(), 0));
	CHECK(IsEqual(triangle.GetVertex1().GetCoordY(), 0));

	CHECK(IsEqual(triangle.GetVertex2().GetCoordX(), 3));
	CHECK(IsEqual(triangle.GetVertex2().GetCoordY(), 0));

	CHECK(IsEqual(triangle.GetVertex3().GetCoordX(), 3));
	CHECK(IsEqual(triangle.GetVertex3().GetCoordY(), 3));

	CHECK(IsEqual(triangle.GetPerimeter(), 3 + 3 + 3 * sqrt(2)));
	CHECK(IsEqual(triangle.GetArea(), 4.5));
};
