#pragma once
#include "CPoint.h"
#include "CShape.h"

class CLineSegment final : public CShape
{
public:
	CLineSegment(const CPoint & start, const CPoint & end, const uint32_t outlineColor);
	~CLineSegment();

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};
