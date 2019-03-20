#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "RemoteControl.h"

void VerifyCommand(CRemoteControl& remoteControl, std::stringstream& input, std::stringstream& output, const std::string& command, const std::string& expectedOutput)
{
	/* ������� ���������� ������� */
	output = std::stringstream();
	input = std::stringstream();

	input << command;

	remoteControl.HandleComand();

	CHECK(output.str() == expectedOutput);
}

TEST_CASE("Test how CRemoteControl instance work")
{
	CCar car;

	std::stringstream input;
	std::stringstream output;

	CRemoteControl remoteControl(car, input, output);

	/* ��������� ��������� ��������� ������ */
	VerifyCommand(remoteControl, input, output, "Info", "Car info:\n\tEngine state: Off\n\tDirection: Not moving\n\tSpeed: 0\n\tGear: 0\n");



	/* �������� ��������� � ��������� ��������� */
	VerifyCommand(remoteControl, input, output, "EngineOn", "Engine is turned on\n");

	/* ������� �������� ��������� ��� ���, ��������� ��������� � ������������� ������� ��� */
	VerifyCommand(remoteControl, input, output, "EngineOn", "Can not turn engine on\n");

	/* ��������� ��������� ������ */
	VerifyCommand(remoteControl, input, output, "Info", "Car info:\n\tEngine state: On\n\tDirection: Not moving\n\tSpeed: 0\n\tGear: 0\n");



	/* ����������� �������� �� ������, ��������� ��������� */
	VerifyCommand(remoteControl, input, output, "SetGear 1", "Gear is shifted to 1\n");

	/* ������� ����������� �������� �� ������, ��������� ��������� */
	VerifyCommand(remoteControl, input, output, "SetGear 2", "Can not shift gear to 2\n");

	/* ��������� ��������� ������ */
	VerifyCommand(remoteControl, input, output, "Info", "Car info:\n\tEngine state: On\n\tDirection: Not moving\n\tSpeed: 0\n\tGear: 1\n");



	/* ��������� ������, ��������� ��������� */
	VerifyCommand(remoteControl, input, output, "SetSpeed 25", "Speed is changed to 25\n");

	/* �������� ��������� ������ �� ����������� �� ������ �������� ��������, ��������� ��������� */
	VerifyCommand(remoteControl, input, output, "SetSpeed 35", "Can not change speed to 35\n");

	/* ��������� ��������� ������ */
	VerifyCommand(remoteControl, input, output, "Info", "Car info:\n\tEngine state: On\n\tDirection: Not moving\n\tSpeed: 25\n\tGear: 1\n");



	/* �������� ������������� �� ������ �������� � ��������� ��������, ��������� ��������� */
	VerifyCommand(remoteControl, input, output, "SetGear -1", "Can not shift gear to -1\n");



	/* ����������� �������� �� ������, ��������� ��������� */
	VerifyCommand(remoteControl, input, output, "SetGear 2", "Gear is shifted to 2\n");



	/* ����������� �������� �� �����������, ��������� ��������� */
	VerifyCommand(remoteControl, input, output, "SetGear 0", "Gear is shifted to 0\n");

	/* ������� ��������� ������ �� ����������� ��������, ��������� ��������� */
	VerifyCommand(remoteControl, input, output, "SetSpeed 30", "Can not change speed to 30\n");



	/* �������� ������ */
	VerifyCommand(remoteControl, input, output, "SetSpeed 0", "Speed is changed to 0\n");


	/* ��������� ��������� � ��������� ��������� */
	VerifyCommand(remoteControl, input, output, "EngineOff", "Engine is turned off\n");

	/* ��������� ��������� ������ */
	VerifyCommand(remoteControl, input, output, "Info", "Car info:\n\tEngine state: Off\n\tDirection: Not moving\n\tSpeed: 0\n\tGear: 0\n");


	/* �������� ��������� ������������ ������� */
	VerifyCommand(remoteControl, input, output, "Fly", "Unknown command\n");

	/* ��������� ��������� ������ */
	VerifyCommand(remoteControl, input, output, "Info", "Car info:\n\tEngine state: Off\n\tDirection: Not moving\n\tSpeed: 0\n\tGear: 0\n");
}