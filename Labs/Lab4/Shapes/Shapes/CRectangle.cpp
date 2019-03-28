#include "pch.h"
#include "CRectangle.h"

CRectangle::CRectangle(const CPoint& leftTop, const CPoint& rightBottom, const uint32_t outlineColor, const uint32_t fillColor)
	: CSolidShape(outlineColor, fillColor)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

CRectangle::~CRectangle()
{
}

double CRectangle::GetArea() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}

double CRectangle::GetPerimeter() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}

std::string CRectangle::ToString() const
{
	// TODO: Add your implementation code here.
	return std::string();
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}

double CRectangle::GetHeight() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}
