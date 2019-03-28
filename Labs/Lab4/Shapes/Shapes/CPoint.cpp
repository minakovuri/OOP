#include "pch.h"
#include "CPoint.h"

CPoint::CPoint(const double x, const double y)
	: m_x(x)
	, m_y(y)
{
}

CPoint::~CPoint()
{
}

double CPoint::GetCoordX() const
{
	return m_x;
}

double CPoint::GetCoordY() const
{
	return m_y;
}
