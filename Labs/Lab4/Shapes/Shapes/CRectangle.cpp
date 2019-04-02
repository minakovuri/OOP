#include "pch.h"
#include "CRectangle.h"

CRectangle::CRectangle(const CPoint& leftTop, const CPoint& rightBottom, const uint32_t outlineColor, const uint32_t fillColor)
	: CSolidShape(outlineColor, fillColor)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
	if (leftTop.GetCoordX() >= rightBottom.GetCoordX())
	{
		throw std::invalid_argument("Rectangle must have left vertex less than right by OX");
	}

	if (leftTop.GetCoordY() <= rightBottom.GetCoordY())
	{
		throw std::invalid_argument("Rectangle must have left vertex larger than right by OY");
	}
}

CRectangle::~CRectangle()
{
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
	return m_rightBottom.GetCoordX() - m_leftTop.GetCoordX();
}

double CRectangle::GetHeight() const
{
	return m_leftTop.GetCoordY() - m_rightBottom.GetCoordY();
}

double CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

double CRectangle::GetPerimeter() const
{
	return 2 * (GetWidth() + GetHeight());
}

std::string CRectangle::ToString() const
{
	// TODO: Add your implementation code here.
	return std::string();
}
