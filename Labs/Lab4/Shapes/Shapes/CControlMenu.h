#pragma once
#include "pch.h"
#include "CShape.h"

using VectorOfStrings = std::vector<std::string>;
using ShapePtr = std::unique_ptr<CShape>;

class CÑontrolMenu
{
public:
	CÑontrolMenu(std::istream & input, std::ostream & output, std::ostream & errstr);
	~CÑontrolMenu();

	void HandleCommands();

private:
	void ExecuteCommand(const std::string& commandLine);

	void CreateLineSegment(const VectorOfStrings& commands);
	void CreateTriangle(const VectorOfStrings& commands);
	void CreateRectangle(const VectorOfStrings& commands);
	void CreateCircle(const VectorOfStrings& commands);

	void GetShapesInfo();
	void DeleteShapes();

	CShape* GetShapeWithMaxArea();
	CShape* GetShapeWithMinPerimeter();

	std::istream& m_input;
	std::ostream& m_output;
	std::ostream& m_errstr;

	std::vector<ShapePtr> m_shapes;
};
