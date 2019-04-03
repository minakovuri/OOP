#include "pch.h"
#include "CControlMenu.h"
#include "CFactory.h"

const std::string LINE_SEGMENT_COMMAND_BEGINNING = "LINE_SEGMENT";
const std::string TRIANGLE_COMMAND_BEGINNING = "TRIANGLE";
const std::string RECTANGLE_COMMAND_BEGINNING = "RECTANGLE";
const std::string CIRCLE_COMMAND_BEGINNING = "CIRCLE";
const std::string INFO_COMMAND = "INFO";

C�ontrolMenu::C�ontrolMenu(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

C�ontrolMenu::~C�ontrolMenu()
{
}

void C�ontrolMenu::HandleCommands()
{
	std::string commandLine;

	while (std::getline(m_input, commandLine))
	{
		ExecuteCommand(commandLine);
	}
}

void C�ontrolMenu::ExecuteCommand(const std::string& commandLine)
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
}

void C�ontrolMenu::CreateLineSegment(const VectorOfStrings& commands)
{
	// TODO	
}

void C�ontrolMenu::CreateTriangle(const VectorOfStrings& commands)
{
	// TODO: Add your implementation code here.
}

void C�ontrolMenu::CreateRectangle(const VectorOfStrings& commands)
{
	// TODO: Add your implementation code here.
}

void C�ontrolMenu::CreateCircle(const VectorOfStrings& commands)
{
	// TODO: Add your implementation code here.
}

void C�ontrolMenu::GetShapesInfo()
{
	// TODO: Add your implementation code here.
}
