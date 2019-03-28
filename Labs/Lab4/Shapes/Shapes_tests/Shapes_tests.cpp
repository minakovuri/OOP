#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../Shapes/CLineSegment.h"
#include "../Shapes/CPoint.h"
#include "../Shapes/CTriangle.h"

const uint32_t BLACK_COLOR = 0x000000;
const uint32_t RED_COLOR = 0xff0000;

TEST_CASE("Test CPoint class instance creation")
{
	CPoint point(10.2, 5.6);

	CHECK(point.GetCoordX() == 10.2);
	CHECK(point.GetCoordY() == 5.6);
}

TEST_CASE("Test CLineSegment class instance creation")
{
	CPoint startPoint(0, 0);
	CPoint endPoint(45.5, -23.7);

	CLineSegment lineSegment(startPoint, endPoint, BLACK_COLOR);

	CHECK(lineSegment.GetStartPoint().GetCoordX() == 0);
	CHECK(lineSegment.GetStartPoint().GetCoordY() == 0);

	CHECK(lineSegment.GetEndPoint().GetCoordX() == 45.5);
	CHECK(lineSegment.GetEndPoint().GetCoordY() == -23.7);

	CHECK(lineSegment.GetOutlineColor() == BLACK_COLOR);

	CHECK(lineSegment.GetArea() == 0);

	CHECK(lineSegment.GetPerimeter() == 0);
};

TEST_CASE("Test CTriangle class instance creation")
{
	CPoint vertex1(0, 0);
	CPoint vertex2(3.0, 0);
	CPoint vertex3(3.0, 3.0);

	CTriangle triangle(vertex1, vertex2, vertex3, BLACK_COLOR, RED_COLOR);

	CHECK(triangle.GetPerimeter() == 10.243);
	CHECK(triangle.GetArea() == 4.5);
};
