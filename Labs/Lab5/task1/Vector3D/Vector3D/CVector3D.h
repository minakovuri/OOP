#pragma once
class CVector3D
{
public:
	CVector3D();
	CVector3D(double x0, double y0, double z0);

	~CVector3D();

	double GetLength() const;

	CVector3D const operator+() const;
	CVector3D const operator-() const;

	CVector3D const operator+(CVector3D const& vector2) const;
	CVector3D const operator-(CVector3D const& vector2) const;

	CVector3D operator+=(CVector3D const& vector2);
	CVector3D operator-=(CVector3D const& vector2);

	CVector3D const operator*(double scalar) const;
	CVector3D const operator/(double scalar) const;

	CVector3D operator*=(CVector3D const& vector2);
	CVector3D operator/=(CVector3D const& vector2);

	bool operator==(CVector3D const& other) const;
	bool operator!=(CVector3D const& other) const;

	double x, y, z;
};

CVector3D const operator*(double scalar, CVector3D const& vector);

CVector3D Normalize(CVector3D const& vector);

CVector3D CrossProduct(CVector3D const& vector1, CVector3D const& vector2);

double DotProduct(CVector3D const& vector1, CVector3D const& vector2);

std::ostream& operator<<(std::ostream& stream, CVector3D const& vector);

std::istream& operator>>(std::istream& stream, CVector3D & vector);
