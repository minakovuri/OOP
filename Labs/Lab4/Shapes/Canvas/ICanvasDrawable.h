#pragma once
#include "ICanvas.h"

class ICanvasDrawable
{
public:
	ICanvasDrawable() = default;
	virtual ~ICanvasDrawable() = default;

	virtual void Draw(ICanvas canvas) = 0;
};
