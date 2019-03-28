#pragma once
#include "CPoint.h"
#include "CSolidShape.h"
#include <array>

class CTriangle : public CSolidShape
{
public:
	CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, const uint32_t outlineColor, const uint32_t fillColor);
	~CTriangle();

	double GetPerimeter() const override;
	double GetArea() const override;
	std::string ToString() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	std::array<CPoint, 3> m_vertices;
};
