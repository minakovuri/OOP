#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(const CPoint& leftTop, const CPoint& rightBottom, const uint32_t outlineColor, const uint32_t fillColor);
	~CRectangle();

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
};
