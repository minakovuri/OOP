#pragma once
#include "CCar.h"
#include <map>
#include <functional>
#include <iostream>

class CRemoteControl
{
public:
	CRemoteControl(CCar& car, std::istream& input, std::ostream& output);
	~CRemoteControl();

private:
	CCar& m_car;
	std::istream& m_input;
	std::ostream& m_output;

private:
	void Info();
	bool EngineOn();
	bool EngineOff();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

public:
	void HandleComand();
};
