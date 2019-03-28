#include "pch.h"
#include "CShape.h"
#include "CSolidShape.h"

CSolidShape::CSolidShape(const uint32_t outlineColor, const uint32_t fillColor)
	: CShape(outlineColor)
	, m_fillColor(fillColor)
{
}

CSolidShape::~CSolidShape()
{
}

uint32_t CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

void CSolidShape::SetFillColor(uint32_t fillColor)
{
	m_fillColor = fillColor;
}
