#include "pch.h"
#include "CFactory.h"

#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"

CFactory::CFactory()
{
}

CFactory::~CFactory()
{
}

ShapePtr CFactory::CreateLineSegment(const VectorOfStrings& params)
{
	if (params.size() != 5)
	{
		throw std::invalid_argument("Incorrect number of parameters");
	}

	const CPoint startPoint(std::stod(params[0]), std::stod(params[1]));
	const CPoint endPoint(std::stod(params[2]), std::stod(params[3]));

	const uint32_t outlineColor = std::stoul(params[4], nullptr, 16);

	return std::make_unique<CLineSegment>(startPoint, endPoint, outlineColor);
}

ShapePtr CFactory::CreateTriangle(const VectorOfStrings& params)
{
	if (params.size() != 8)
	{
		throw std::invalid_argument("Incorrect number of parameters");
	}

	const CPoint vertex1(std::stod(params[0]), std::stod(params[1]));
	const CPoint vertex2(std::stod(params[2]), std::stod(params[3]));
	const CPoint vertex3(std::stod(params[4]), std::stod(params[5]));

	const uint32_t outlineColor = std::stoul(params[6], nullptr, 16);

	const uint32_t fillColor = std::stoul(params[7], nullptr, 16);

	return std::make_unique<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
}

ShapePtr CFactory::CreateRectangle(const VectorOfStrings& params)
{
	if (params.size() != 6)
	{
		throw std::invalid_argument("Incorrect number of parameters");
	}

	const CPoint leftTop(std::stod(params[0]), std::stod(params[1]));
	const CPoint rightBottom(std::stod(params[2]), std::stod(params[3]));

	const uint32_t outlineColor = std::stoul(params[4], nullptr, 16);

	const uint32_t fillColor = std::stoul(params[5], nullptr, 16);

	return std::make_unique<CRectangle>(leftTop, rightBottom, outlineColor, fillColor);
}

ShapePtr CFactory::CreateCircle(const VectorOfStrings& params)
{
	if (params.size() != 5)
	{
		throw std::invalid_argument("Incorrect number of parameters");
	}

	const CPoint center(std::stod(params[0]), std::stod(params[1]));
	const double radius = std::stod(params[2]);

	const uint32_t outlineColor = std::stoul(params[3], nullptr, 16);

	const uint32_t fillColor = std::stoul(params[4], nullptr, 16);

	return std::make_unique<CCircle>(center, radius, outlineColor, fillColor);
}
