#pragma once
#include "pch.h"
#include "CShape.h"

using VectorOfStrings = std::vector<std::string>;

class CÑontrolMenu
{
public:
	CÑontrolMenu(std::istream & input, std::ostream & output);
	~CÑontrolMenu();

	void HandleCommands();

private:
	void ExecuteCommand(const std::string& commandLine);

	void CreateLineSegment(const VectorOfStrings& commands);
	void CreateTriangle(const VectorOfStrings& commands);
	void CreateRectangle(const VectorOfStrings& commands);
	void CreateCircle(const VectorOfStrings& commands);

	void GetShapesInfo();

	std::istream& m_input;
	std::ostream& m_output;

	std::vector<std::unique_ptr<CShape>> m_shapes;
};
