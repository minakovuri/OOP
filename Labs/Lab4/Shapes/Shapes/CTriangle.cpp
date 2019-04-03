#include "pch.h"
#include "CTriangle.h"

CTriangle::CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, const uint32_t outlineColor, const uint32_t fillColor)
	: CSolidShape(outlineColor, fillColor)
	, m_vertices({ vertex1, vertex2, vertex3 })
{
	auto a = std::hypot(m_vertices[0].GetCoordX() - m_vertices[1].GetCoordX(), m_vertices[0].GetCoordY() - m_vertices[1].GetCoordY());
	auto b = std::hypot(m_vertices[1].GetCoordX() - m_vertices[2].GetCoordX(), m_vertices[1].GetCoordY() - m_vertices[2].GetCoordY());
	auto c = std::hypot(m_vertices[0].GetCoordX() - m_vertices[2].GetCoordX(), m_vertices[0].GetCoordY() - m_vertices[2].GetCoordY());

	if (((a + b) <= c) || ((a + c) <= b) || ((b + c) <= a))
	{
		throw std::invalid_argument("This triangle is degenerate");
	}
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetPerimeter() const
{
	return std::hypot(m_vertices[0].GetCoordX() - m_vertices[1].GetCoordX(), m_vertices[0].GetCoordY() - m_vertices[1].GetCoordY())
		+ std::hypot(m_vertices[1].GetCoordX() - m_vertices[2].GetCoordX(), m_vertices[1].GetCoordY() - m_vertices[2].GetCoordY())
		+ std::hypot(m_vertices[0].GetCoordX() - m_vertices[2].GetCoordX(), m_vertices[0].GetCoordY() - m_vertices[2].GetCoordY());
}

double CTriangle::GetArea() const
{
	auto p = GetPerimeter() / 2;

	auto a = std::hypot(m_vertices[0].GetCoordX() - m_vertices[1].GetCoordX(), m_vertices[0].GetCoordY() - m_vertices[1].GetCoordY());
	auto b = std::hypot(m_vertices[1].GetCoordX() - m_vertices[2].GetCoordX(), m_vertices[1].GetCoordY() - m_vertices[2].GetCoordY());
	auto c = std::hypot(m_vertices[0].GetCoordX() - m_vertices[2].GetCoordX(), m_vertices[0].GetCoordY() - m_vertices[2].GetCoordY());

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

std::string CTriangle::ToString() const
{
	// TODO: Add your implementation code here.
	return std::string();
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertices[0];
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertices[1];
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertices[2];
}
