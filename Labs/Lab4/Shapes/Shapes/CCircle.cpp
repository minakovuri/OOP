#include "pch.h"
#include "CCircle.h"

CCircle::CCircle(const CPoint& center, const double radius, const uint32_t outlineColor, const uint32_t fillColor)
	: CSolidShape(outlineColor, fillColor)
	, m_center(center)
	, m_radius(radius)
{
}

CCircle::~CCircle()
{
}

double CCircle::GetArea() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}

double CCircle::GetPerimeter() const
{
	// TODO: Add your implementation code here.
	return 0.0;
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
