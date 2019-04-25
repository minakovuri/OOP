#define CATCH_CONFIG_MAIN
#include "../../../../../catch/catch.hpp"

#include "../Vector3D/CVector3D.h"
#include "../Vector3D/MathUtils.h"

TEST_CASE("Check of creating a vector without initializing the coordinates")
{
	CVector3D vector3d;

	CHECK(vector3d.x == 0);
	CHECK(vector3d.y == 0);
	CHECK(vector3d.z == 0);
}

TEST_CASE("Check of creating a vector with the initialization of coordinates")
{
	CVector3D vector3d(13.3, 12.6, -34.567);

	CHECK(IsEqual(vector3d.x, 13.3));
	CHECK(IsEqual(vector3d.y, 12.6));
	CHECK(IsEqual(vector3d.z, -34.567));
}

TEST_CASE("Checking the unary vector '+' operator")
{
	CVector3D vector1(13.3, 12.6, -34.567);

	CVector3D vector2 = +vector1;

	CHECK(IsEqual(vector2.x, 13.3));
	CHECK(IsEqual(vector2.y, 12.6));
	CHECK(IsEqual(vector2.z, -34.567));
}

TEST_CASE("Checking the unary vector '-' operator")
{
	CVector3D vector1(10.2, 34.5, -56.123);

	CVector3D vector2 = -vector1;

	CHECK(IsEqual(vector2.x, -10.2));
	CHECK(IsEqual(vector2.y, -34.5));
	CHECK(IsEqual(vector2.z, 56.123));
}

TEST_CASE("Checking the binary vectors '+' operator")
{
	CVector3D vector1(10.2, 34.5, -56.123);
	CVector3D vector2(0, 10, -1);

	CVector3D vector3 = vector1 + vector2;

	CHECK(IsEqual(vector3.x, 10.2));
	CHECK(IsEqual(vector3.y, 44.5));
	CHECK(IsEqual(vector3.z, -57.123));
}

TEST_CASE("Checking the binary vectors '-' operator")
{
	CVector3D vector1(10.2, 34.5, -56.123);
	CVector3D vector2(0, 10, -1);

	CVector3D vector3 = vector1 - vector2;

	CHECK(IsEqual(vector3.x, 10.2));
	CHECK(IsEqual(vector3.y, 24.5));
	CHECK(IsEqual(vector3.z, -55.123));
}

TEST_CASE("Checking the vectors '+=' operator")
{
	CVector3D vector1(12.56, -4.12, 8.09);
	CVector3D vector2(-8.1234, 34.12, 10.2);

	vector1 += vector2;

	CHECK(IsEqual(vector1.x, 4.4366));
	CHECK(IsEqual(vector1.y, 30));
	CHECK(IsEqual(vector1.z, 18.29));
}

TEST_CASE("Checking the vectors '-=' operator")
{
	CVector3D vector1(12.56, -4.12, 8.09);
	CVector3D vector2(-8.1234, 34.12, 10.2);

	vector1 -= vector2;

	CHECK(IsEqual(vector1.x, 20.6834));
	CHECK(IsEqual(vector1.y, -38.24));
	CHECK(IsEqual(vector1.z, -2.11));
}

TEST_CASE("Check multiplication of vector by scalar")
{
	CVector3D vector1(12.56, -4.12, 8.09);

	CVector3D vector2 = vector1 * 5.56;

	CHECK(IsEqual(vector2.x, 69.8336));
	CHECK(IsEqual(vector2.y, -22.9072));
	CHECK(IsEqual(vector2.z, 44.9804));
}

TEST_CASE("Check multiplication of a scalar by a vector")
{
	CVector3D vector1(12.56, -4.12, 8.09);

	CVector3D vector2 = 5.56 * vector1;

	CHECK(IsEqual(vector2.x, 69.8336));
	CHECK(IsEqual(vector2.y, -22.9072));
	CHECK(IsEqual(vector2.z, 44.9804));
}

TEST_CASE("Check vector division by scalar")
{
	CVector3D vector1(10, -4, 8);

	CVector3D vector2 = vector1 / 2;

	CVector3D vector3;
	CHECK_THROWS_AS(vector3 = vector1 / 0.0, std::logic_error);

	CHECK(IsEqual(vector2.x, 5));
	CHECK(IsEqual(vector2.y, -2));
	CHECK(IsEqual(vector2.z, 4));
}

TEST_CASE("Checking the vectors '*=' operator")
{
	CVector3D vector1(12.56, -4.12, 8.09);
	CVector3D vector2(-1.5, 2.5, 10.2);

	vector1 *= vector2;

	CHECK(IsEqual(vector1.x, -18.84));
	CHECK(IsEqual(vector1.y, -10.3));
	CHECK(IsEqual(vector1.z, 82.518));
}

TEST_CASE("Checking the vectors '/=' operator")
{
	CVector3D vector1(10, -4, 8);
	CVector3D vector2(2, 2, 2);
	CVector3D vector3(0, 1, 2);

	vector1 /= vector2;

	CHECK_THROWS_AS(vector2 /= vector3, std::logic_error);

	CHECK(IsEqual(vector1.x, 5));
	CHECK(IsEqual(vector1.y, -2));
	CHECK(IsEqual(vector1.z, 4));
}

TEST_CASE("Vector length calculation check")
{
	CVector3D vector1(2, 2, 2);
	CHECK(IsEqual(vector1.GetLength(), sqrt(std::pow(2.0, 2.0) + std::pow(2.0, 2.0) + std::pow(2.0, 2.0))));
}

TEST_CASE("Checking the vectors '==' operator")
{
	CVector3D vector1(10, -4, 8);
	CVector3D vector2(2, 2, 2);
	CVector3D vector3 = +vector1;

	CHECK(vector1 == vector3);
	CHECK_FALSE(vector1 == vector2);
}

TEST_CASE("Checking the vectors '!=' operator")
{
	CVector3D vector1(10, -4, 8);
	CVector3D vector2(2, 2, 2);
	CVector3D vector3 = +vector1;

	CHECK(vector1 != vector2);
	CHECK_FALSE(vector1 != vector3);
}

TEST_CASE("Check vector normalization")
{
	CVector3D vector(10, -4, 8);

	const auto vectorLentgh = sqrt(std::pow(10.0, 2.0) + std::pow(-4.0, 2.0) + std::pow(8.0, 2.0));

	CVector3D normVector = Normalize(vector);

	CHECK(IsEqual(normVector.x, 10 / vectorLentgh));
	CHECK(IsEqual(normVector.y, -4 / vectorLentgh));
	CHECK(IsEqual(normVector.z, 8 / vectorLentgh));
}

TEST_CASE("Check vector with length 0.0 normalization")
{
	CVector3D vector(0, 0, 0);

	CVector3D normVector;

	CHECK_THROWS_AS(normVector = Normalize(vector), std::logic_error);

}

TEST_CASE("Check cross product of vectors")
{
	CVector3D vector1(1, 2, 3);
	CVector3D vector2(4, 5, 6);

	CVector3D vector3 = CrossProduct(vector1, vector2);

	CHECK(IsEqual(vector3.x, -3));
	CHECK(IsEqual(vector3.y, 6));
	CHECK(IsEqual(vector3.z, -3));
}

TEST_CASE("Check dot product of vectors")
{
	CVector3D vector1(1, 2, 3);
	CVector3D vector2(4, 5, 6);

	const auto scalar = DotProduct(vector1, vector2);

	CHECK(scalar == 32);
}

TEST_CASE("Test the '<<' operator")
{
	std::stringstream output;

	CVector3D vector(12.56, -4.12, 8.09);

	output << vector;

	CHECK(output.str() == "12.56 -4.12 8.09\n");
}

TEST_CASE("Test the '>>' operator")
{
	std::stringstream input;

	input << "12.56 -4.12 8.09\n";

	double x, y, z;

	input >> x >> y >> z;

	CVector3D vector(x, y, z);

	CHECK(IsEqual(vector.x, 12.56));
	CHECK(IsEqual(vector.y, -4.12));
	CHECK(IsEqual(vector.z, 8.09));
}