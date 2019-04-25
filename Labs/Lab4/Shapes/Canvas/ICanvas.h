#pragma once

class ICanvas
{
public:
	ICanvas() = default;
	virtual ~ICanvas() = default;

	virtual void DrawLine() = 0;
	virtual void FillPolygon() = 0;
	virtual void DrawCircle() = 0;
	virtual void FillCircle() = 0;
};
