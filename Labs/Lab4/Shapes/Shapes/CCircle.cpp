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
	std::stringstream buffer;
	buffer << std::fixed << std::setprecision(2);

	buffer << "Ñircle:" << std::endl;

	CPoint center = GetCenter();

	buffer << "  Center: " << center.GetCoordX() << ' ' << center.GetCoordY() << std::endl;
	buffer << "  Radius: " << GetRadius() << std::endl;

	buffer << "  Area: " << GetArea() << std::endl;
	buffer << "  Perimeter: " << GetPerimeter() << std::endl;

	buffer << "  Outline color: " << std::hex << std::setw(6) << std::setfill('0') << GetOutlineColor() << std::dec << std::endl;
	buffer << "  Fill color: " << std::hex << std::setw(6) << std::setfill('0') << GetFillColor() << std::dec << std::endl;

	return buffer.str();
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
