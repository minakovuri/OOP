#include "pch.h"
#include "CCircle.h"

CCircle::CCircle(const CPoint& center, const double radius, const uint32_t outlineColor, const uint32_t fillColor)
	: CSolidShape(outlineColor, fillColor)
	, m_center(center)
	, m_radius(radius)
{
	if (radius <= 0)
	{
		throw std::invalid_argument("Circle must have radius larger than 0");
	}
}

CCircle::~CCircle()
{
}

double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{
	// TODO: Add your implementation code here.
	return std::string();
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
