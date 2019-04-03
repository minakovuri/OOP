#include "pch.h"
#include "CLineSegment.h"

CLineSegment::CLineSegment(const CPoint& start, const CPoint& end, const uint32_t outlineColor)
	: CShape(outlineColor)
	, m_startPoint(start)
	, m_endPoint(end)
{
}

CLineSegment::~CLineSegment()
{
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	return 0.0;
}

std::string CLineSegment::ToString() const
{
	std::stringstream buffer;
	buffer << std::fixed << std::setprecision(2);

	buffer << "Line segment:" << '\n';
	buffer << '\t' << "Area: " << GetArea() << '\n';
	buffer << '\t' << "Perimeter: " << GetPerimeter() << '\n';
	buffer << '\t' << "Outline color: " << std::hex << GetOutlineColor() << std::dec << '\n';

	CPoint startPoint = GetStartPoint();
	buffer << '\t' << "Start point: " << startPoint.GetCoordX() << ' ' << startPoint.GetCoordY() << '\n';

	CPoint endPoint = GetEndPoint();
	buffer << '\t' << "End point: " << endPoint.GetCoordX() << ' ' << endPoint.GetCoordY() << '\n';

	return buffer.str();
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}
