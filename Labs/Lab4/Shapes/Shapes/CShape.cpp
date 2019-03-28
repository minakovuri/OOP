#include "pch.h"
#include "CShape.h"

CShape::CShape(const uint32_t outlineColor)
	: m_outlineColor(outlineColor)
{
}

CShape::~CShape()
{
}

uint32_t CShape::GetOutlineColor() const
{
	return m_outlineColor;
}
