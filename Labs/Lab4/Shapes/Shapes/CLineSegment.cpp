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

	buffer << "Line segment:" << std::endl;

	CPoint startPoint = GetStartPoint();
	CPoint endPoint = GetEndPoint();

	buffer << "  Start point: " << startPoint.GetCoordX() << ' ' << startPoint.GetCoordY() << std::endl;
	buffer << "  End point: " << endPoint.GetCoordX() << ' ' << endPoint.GetCoordY() << std::endl;

	buffer << "  Area: " << GetArea() << std::endl;
	buffer << "  Perimeter: " << GetPerimeter() << std::endl;
	buffer << "  Outline color: " << std::hex << std::setw(6) << std::setfill('0') << GetOutlineColor() << std::dec << std::endl;

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
