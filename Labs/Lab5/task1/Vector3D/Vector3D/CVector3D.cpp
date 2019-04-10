#include "pch.h"
#include "CVector3D.h"
#include "MathUtils.h"

CVector3D::CVector3D()
	: x(0)
	, y(0)
	, z(0)
{
}

CVector3D::CVector3D(double x0, double y0, double z0)
	: x(x0)
	, y(y0)
	, z(z0)
{
}

CVector3D::~CVector3D()
{
}

double CVector3D::GetLength() const
{
	return sqrt(std::pow(x, 2.0) + std::pow(y, 2.0) + std::pow(z, 2.0));
}

CVector3D const CVector3D::operator+() const
{
	return CVector3D(x, y, z);
}

CVector3D const CVector3D::operator-() const
{
	return CVector3D(-1.0 * x, -1.0 * y, -1.0 * z);
}

CVector3D const CVector3D::operator+(CVector3D const& vector2) const
{
	return CVector3D(x + vector2.x, y + vector2.y, z + vector2.z);
}

CVector3D const CVector3D::operator-(CVector3D const& vector2) const
{
	return CVector3D(x - vector2.x, y - vector2.y, z - vector2.z);
}

CVector3D CVector3D::operator+=(CVector3D const& vector2)
{
	x += vector2.x;
	y += vector2.y;
	z += vector2.z;

	return *this;
}

CVector3D CVector3D::operator-=(CVector3D const& vector2)
{
	x -= vector2.x;
	y -= vector2.y;
	z -= vector2.z;

	return *this;
}

CVector3D const CVector3D::operator*(double scalar) const
{
	return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D const operator*(double scalar, CVector3D const& vector)
{
	return CVector3D(scalar * vector.x, scalar * vector.y, scalar * vector.z);
}

CVector3D const CVector3D::operator/(double scalar) const
{
	return CVector3D(x / scalar, y / scalar, z / scalar);
}

CVector3D CVector3D::operator*=(CVector3D const& vector2)
{
	x *= vector2.x;
	y *= vector2.y;
	z *= vector2.z;

	return *this;
}

CVector3D CVector3D::operator/=(CVector3D const& vector2)
{
	x /= vector2.x;
	y /= vector2.y;
	z /= vector2.z;

	return *this;
}

bool CVector3D::operator==(CVector3D const& other) const
{
	const auto currentVectorLength = GetLength();
	const auto otherVectorLenth = other.GetLength();

	if (IsEqual(currentVectorLength, otherVectorLenth))
	{
		return true;
	}

	return false;
}

bool CVector3D::operator!=(CVector3D const& other) const
{
	const auto currentVectorLength = GetLength();
	const auto otherVectorLenth = other.GetLength();

	if (IsEqual(currentVectorLength, otherVectorLenth))
	{
		return false;
	}

	return true;
}