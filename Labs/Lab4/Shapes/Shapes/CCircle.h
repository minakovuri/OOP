#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CCircle : public CSolidShape
{
public:
	CCircle(const CPoint& center, const double radius, const uint32_t outlineColor, const uint32_t fillColor);
	~CCircle();

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center;
	double m_radius;
};
