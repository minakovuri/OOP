#pragma once
#include "IShape.h"

class ISolidShape : virtual public IShape
{
public:
	ISolidShape() = default;
	virtual ~ISolidShape() = default;

	virtual uint32_t GetFillColor() const = 0;
	virtual void SetFillColor(uint32_t) = 0;
};
