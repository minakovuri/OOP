#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"

#include "../Shapes/CCircle.h"
#include "../Shapes/CLineSegment.h"
#include "../Shapes/CPoint.h"
#include "../Shapes/CRectangle.h"
#include "../Shapes/CTriangle.h"

const uint32_t BLACK_COLOR = 0x000000;
const uint32_t RED_COLOR = 0xff0000;

bool IsEqual(const double a, const double b)
{
	return std::abs(a - b) < DBL_EPSILON;
}

TEST_CASE("Create point and check it coordinates")
{
	CPoint point(10.2, 5.6);

	CHECK(IsEqual(point.GetCoordX(), 10.2));
	CHECK(IsEqual(point.GetCoordY(), 5.6));
}

TEST_CASE("Create black line segment and check it paramaters")
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

TEST_CASE("Create correct triangle with black outline and red filling, then check it parameters")
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

	CHECK(triangle.GetOutlineColor() == BLACK_COLOR);
	CHECK(triangle.GetFillColor() == RED_COLOR);
};

TEST_CASE("Try to create degenerate triangle")
{
	CPoint vertex1(9.0, 2.0);
	CPoint vertex2(12.0, 4.0);
	CPoint vertex3(15.0, 6.0);

	CHECK_THROWS_AS(CTriangle(vertex1, vertex2, vertex3, BLACK_COLOR, RED_COLOR), std::invalid_argument);
}

TEST_CASE("Create correct rectangle with black outline and red filling, then check it paramaters")
{
	CPoint leftTop(2.0, 4.0);
	CPoint rightBottom(7.0, 2.0);

	CRectangle rectangle(leftTop, rightBottom, BLACK_COLOR, RED_COLOR);

	CHECK(IsEqual(rectangle.GetLeftTop().GetCoordX(), 2.0));
	CHECK(IsEqual(rectangle.GetLeftTop().GetCoordY(), 4.0));

	CHECK(IsEqual(rectangle.GetRightBottom().GetCoordX(), 7.0));
	CHECK(IsEqual(rectangle.GetRightBottom().GetCoordY(), 2.0));

	CHECK(IsEqual(rectangle.GetWidth(), 5.0));
	CHECK(IsEqual(rectangle.GetHeight(), 2.0));

	CHECK(IsEqual(rectangle.GetPerimeter(), 14.0));

	CHECK(IsEqual(rectangle.GetArea(), 10.0));
}

TEST_CASE("Try to create incorrect rectangle")
{
	CPoint leftTop(2.0, 4.0);
	CPoint rightBottom(7.0, 4.0);

	CHECK_THROWS_AS(CRectangle(leftTop, rightBottom, BLACK_COLOR, RED_COLOR), std::invalid_argument);
}

TEST_CASE("Create circle with black outline and red filling, then check it paramaters")
{
	CPoint center(0, 0);
	double radius = 10.5;

	CCircle circle(center, radius, BLACK_COLOR, RED_COLOR);

	CHECK(IsEqual(circle.GetCenter().GetCoordX(), 0));
	CHECK(IsEqual(circle.GetCenter().GetCoordY(), 0));

	CHECK(IsEqual(circle.GetRadius(), 10.5));

	CHECK(IsEqual(circle.GetPerimeter(), 2 * M_PI * radius));

	CHECK(IsEqual(circle.GetArea(), M_PI * radius * radius));
}

TEST_CASE("Try to create circle with negative radius")
{
	CPoint center(0, 0);
	double radius = -6.67;

	CHECK_THROWS_AS(CCircle(center, radius, BLACK_COLOR, RED_COLOR), std::invalid_argument);
}
