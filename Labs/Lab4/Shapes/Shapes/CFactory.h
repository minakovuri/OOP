#pragma once
#include "CShape.h"
#include "CLineSegment.h"

using ShapePtr = std::unique_ptr<CShape>;
using VectorOfStrings = std::vector<std::string>;

class CFactory
{
public:
	CFactory();
	~CFactory();

	static ShapePtr CreateLineSegment(const VectorOfStrings& params);
	static ShapePtr CreateTriangle(const VectorOfStrings& params);
	static ShapePtr CreateRectangle(const VectorOfStrings& params);
	static ShapePtr CreateCircle(const VectorOfStrings& params);
};
