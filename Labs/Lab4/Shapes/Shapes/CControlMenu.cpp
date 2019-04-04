#include "pch.h"
#include "CControlMenu.h"
#include "CFactory.h"

const std::string LINE_SEGMENT_COMMAND_BEGINNING = "LINE_SEGMENT";
const std::string TRIANGLE_COMMAND_BEGINNING = "TRIANGLE";
const std::string RECTANGLE_COMMAND_BEGINNING = "RECTANGLE";
const std::string CIRCLE_COMMAND_BEGINNING = "CIRCLE";
const std::string INFO_COMMAND = "INFO";
const std::string DELETE_SHAPES_COMMAND = "DELETE_SHAPES";
const std::string SHOW_SHAPE_WITH_MAX_AREA_COMMAND = "SHOW_SHAPE_WITH_MAX_AREA";
const std::string SHOW_SHAPE_WITH_MIN_PERIMETER_COMMAND = "SHOW_SHAPE_WITH_MIN_PERIMETER";

CÑontrolMenu::CÑontrolMenu(std::istream& input, std::ostream& output, std::ostream& errstr)
	: m_input(input)
	, m_output(output)
	, m_errstr(errstr)
{
}

CÑontrolMenu::~CÑontrolMenu()
{
}

void CÑontrolMenu::HandleCommands()
{
	std::string commandLine;

	while (std::getline(m_input, commandLine))
	{
		try
		{
			ExecuteCommand(commandLine);
		}
		catch (const std::exception& e)
		{
			m_errstr << e.what() << std::endl;
		}
	}

	ExecuteCommand("INFO");
}

void CÑontrolMenu::ExecuteCommand(const std::string& commandLine)
{
	auto command(commandLine);
	boost::to_upper(command);

	std::vector<std::string> commands;
	boost::split(commands, command, boost::is_any_of(" \t,"));

	if (commands[0] == LINE_SEGMENT_COMMAND_BEGINNING)
	{
		commands.erase(commands.begin());
		CreateLineSegment(commands);
	}
	else if (commands[0] == TRIANGLE_COMMAND_BEGINNING)
	{
		commands.erase(commands.begin());
		CreateTriangle(commands);
	}
	else if (commands[0] == RECTANGLE_COMMAND_BEGINNING)
	{
		commands.erase(commands.begin());
		CreateRectangle(commands);
	}
	else if (commands[0] == CIRCLE_COMMAND_BEGINNING)
	{
		commands.erase(commands.begin());
		CreateCircle(commands);
	}
	else if (commands[0] == INFO_COMMAND)
	{
		GetShapesInfo();
	}
	else if (commands[0] == DELETE_SHAPES_COMMAND)
	{
		DeleteShapes();
	}
	else if (commands[0] == SHOW_SHAPE_WITH_MAX_AREA_COMMAND)
	{
		auto shape = GetShapeWithMaxArea();
		m_output << shape->ToString() << std::endl;
	}
	else if (commands[0] == SHOW_SHAPE_WITH_MIN_PERIMETER_COMMAND)
	{
		auto shape = GetShapeWithMinPerimeter();
		m_output << shape->ToString() << std::endl;
	}
	else
	{
		throw std::invalid_argument("Unknown command");
	}
}

void CÑontrolMenu::CreateLineSegment(const VectorOfStrings& commands)
{
	m_shapes.push_back(CFactory::CreateLineSegment(commands));
}

void CÑontrolMenu::CreateTriangle(const VectorOfStrings& commands)
{
	m_shapes.push_back(CFactory::CreateTriangle(commands));
}

void CÑontrolMenu::CreateRectangle(const VectorOfStrings& commands)
{
	m_shapes.push_back(CFactory::CreateRectangle(commands));
}

void CÑontrolMenu::CreateCircle(const VectorOfStrings& commands)
{
	m_shapes.push_back(CFactory::CreateCircle(commands));
}

void CÑontrolMenu::GetShapesInfo()
{
	for (const auto& shape : m_shapes)
	{
		m_output << shape->ToString() << std::endl;
	}
}

void CÑontrolMenu::DeleteShapes()
{
	m_shapes.clear();
	m_shapes.shrink_to_fit();
}

CShape* CÑontrolMenu::GetShapeWithMaxArea()
{
	auto result = m_shapes.begin();
	double maxArea = result->get()->GetArea();

	double currArea = 0;

	for (auto it = std::next(m_shapes.begin()); it != m_shapes.end(); ++it)
	{
		currArea = it->get()->GetArea();

		if (currArea > maxArea)
		{
			maxArea = currArea;
			result = it;
		}
	}

	return result->get();
}

CShape* CÑontrolMenu::GetShapeWithMinPerimeter()
{
	auto result = m_shapes.begin();
	double minPerimeter = result->get()->GetPerimeter();

	double currPerimeter = 0;

	for (auto it = std::next(m_shapes.begin()); it != m_shapes.end(); ++it)
	{
		currPerimeter = it->get()->GetPerimeter();

		if (currPerimeter < minPerimeter)
		{
			minPerimeter = currPerimeter;
			result = it;
		}
	}

	return result->get();
}
