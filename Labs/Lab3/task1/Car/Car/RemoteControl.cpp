#include "pch.h"
#include <sstream>
#include "RemoteControl.h"

CRemoteControl::CRemoteControl(CCar& car, std::istream& input, std::ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
{
	m_output << "Welcome to car remote control!\n";
}

CRemoteControl::~CRemoteControl()
{
}

void CRemoteControl::Info()
{
	m_output << "Car info:\n";
	m_output << "\tEngine state: " << m_car.GetEngineState() << "\n";
	m_output << "\tDirection: " << m_car.GetDirection() << "\n";
	m_output << "\tSpeed: " << m_car.GetSpeed() << "\n";
	m_output << "\tGear: " << m_car.GetGear() << "\n";
}

bool CRemoteControl::EngineOn()
{
	if (m_car.TurnEngineOn())
	{
		m_output << "Engine is turned on\n";
		return true;
	}
	
	m_output << "Can not turn engine on\n";
	return false;
}

bool CRemoteControl::EngineOff()
{
	if (m_car.TurnEngineOff())
	{
		m_output << "Engine is turned off\n";
		return true;
	}

	m_output << "Can not turn engine off\n";
	return false;
}

bool CRemoteControl::SetGear(int gear)
{
	if (m_car.SetGear(gear))
	{
		m_output << "Gear is shifted to " << gear << "\n";
		return true;
	}

	m_output << "Can not shift gear to " << gear << "\n";
	return false;
}

bool CRemoteControl::SetSpeed(int speed)
{
	if (m_car.SetSpeed(speed))
	{
		m_output << "Speed is changed to " << speed << "\n";
		return true;
	}

	m_output << "Can not change speed to " << speed << "\n";
	return false;
}

void CRemoteControl::HandleComand()
{
	using namespace std;

	string action;
	m_input >> action;

	if (action == "Info")
	{
		CRemoteControl::Info();
	}
	else if (action == "EngineOn")
	{
		CRemoteControl::EngineOn();
	}
	else if (action == "EngineOff")
	{
		CRemoteControl::EngineOff();
	}
	else if (action == "SetGear")
	{
		int gear;
		m_input >> gear;

		CRemoteControl::SetGear(gear);
	}
	else if (action == "SetSpeed")
	{
		int speed;
		m_input >> speed;

		CRemoteControl::SetSpeed(speed);
	}
	else if (action == "")
	{
		m_output << "Goodbye!\n";
	}
	else 
	{
		m_output << "Unknown command\n";
	}
}
