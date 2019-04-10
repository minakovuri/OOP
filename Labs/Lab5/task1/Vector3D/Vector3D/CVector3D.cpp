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

CVector3D Normalize(CVector3D const& vector)
{
	const auto vectorLength = vector.GetLength();

	return CVector3D(vector.x / vectorLength, vector.y / vectorLength, vector.z / vectorLength);
}

CVector3D CrossProduct(CVector3D const& vector1, CVector3D const& vector2)
{
	return CVector3D(vector1.y * vector2.z - vector1.z * vector2.y, vector1.z * vector2.x - vector1.x * vector2.z, vector1.x * vector2.y - vector1.y * vector2.x);
}

double DotProduct(CVector3D const& vector1, CVector3D const& vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

std::ostream& operator<<(std::ostream& stream, CVector3D const& vector)
{
	stream << vector.x << ' ' << vector.y << ' ' << vector.z << '\n';
	return stream;
}

std::istream& operator>>(std::istream& stream, CVector3D & vector)
{
	double x, y, z;

	if ((stream >> x) && (stream >> y) && (stream >> z))
	{
		vector = CVector3D(x, y, z);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}

	return stream;
}
