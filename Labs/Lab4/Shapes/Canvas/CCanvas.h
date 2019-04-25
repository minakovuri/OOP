#pragma once
#include "ICanvas.h"

class CCanvas : virtual public ICanvas
{
public:
	CCanvas();
	~CCanvas();

	void DrawLine();
	void FillPolygon();
	void DrawCircle();
	void FillCircle();
};
