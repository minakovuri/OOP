#include "pch.h"
#include "CTriangle.h"
#include <math.h>

CTriangle::CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, const uint32_t outlineColor, const uint32_t fillColor)
	: CSolidShape(outlineColor, fillColor)
	, m_vertices({ vertex1, vertex2, vertex3 })
{
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetPerimeter() const
{
	return std::hypotf(m_vertices[0].GetCoordX() - m_vertices[1].GetCoordX(), m_vertices[0].GetCoordY() - m_vertices[1].GetCoordY())
		+ std::hypotf(m_vertices[1].GetCoordX() - m_vertices[2].GetCoordX(), m_vertices[1].GetCoordY() - m_vertices[2].GetCoordY())
		+ std::hypotf(m_vertices[0].GetCoordX() - m_vertices[2].GetCoordX(), m_vertices[0].GetCoordY() - m_vertices[2].GetCoordY());
}

double CTriangle::GetArea() const
{
	auto p = GetPerimeter() / 2;

	auto a = std::hypotf(m_vertices[0].GetCoordX() - m_vertices[1].GetCoordX(), m_vertices[0].GetCoordY() - m_vertices[1].GetCoordY());
	auto b = std::hypotf(m_vertices[1].GetCoordX() - m_vertices[2].GetCoordX(), m_vertices[1].GetCoordY() - m_vertices[2].GetCoordY());
	auto c = std::hypotf(m_vertices[0].GetCoordX() - m_vertices[2].GetCoordX(), m_vertices[0].GetCoordY() - m_vertices[2].GetCoordY());

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
