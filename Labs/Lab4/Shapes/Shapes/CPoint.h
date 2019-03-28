#pragma once

class CPoint
{
public:
	CPoint(const double x, const double y);
	~CPoint();
	double GetCoordX() const;
	double GetCoordY() const;

private:
	double m_x;
	double m_y;
};
