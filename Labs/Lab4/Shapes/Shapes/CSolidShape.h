#pragma once
#include "CShape.h"
#include "ISolidShape.h"

class CSolidShape
	: public ISolidShape
	, public CShape
{
public:
	CSolidShape(const uint32_t outlineColor, const uint32_t fillColor);
	virtual ~CSolidShape();

	uint32_t GetFillColor() const override;
	void SetFillColor(uint32_t) override;

private:
	uint32_t m_fillColor;
};
