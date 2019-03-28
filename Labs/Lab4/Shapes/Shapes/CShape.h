#pragma once
#include <stdint.h>
#include "IShape.h"

class CShape : virtual public IShape
{
public:
	CShape(const uint32_t outlineColor);
	virtual ~CShape();

	uint32_t GetOutlineColor() const override;

private:
	uint32_t m_outlineColor;
};
