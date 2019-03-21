#include "pch.h"
#include <map>
#include <iostream>
#include "CCar.h"

using SpeedRangesMap = std::map<Gear, std::pair<Speed, Speed>>;

const SpeedRangesMap SPEED_RANGES = {
	{ Gear::Reverse, std::make_pair(0, 20) },
	{ Gear::Neutral, std::make_pair(INT_MIN, INT_MAX) },
	{ Gear::First, std::make_pair(0, 30) },
	{ Gear::Second, std::make_pair(20, 50) },
	{ Gear::Third, std::make_pair(30, 60) },
	{ Gear::Fourth, std::make_pair(40, 90) },
	{ Gear::Fifth, std::make_pair(50, 150) },
};

CCar::CCar()
{
	m_engineState = EngineState::Off;
	m_direction = DrivingDirection::NotMoving;
	m_gear = Gear::Neutral;
	m_speed = 0;
}

CCar::~CCar()
{
}

bool CCar::TurnEngineOn()
{
	if (m_engineState == EngineState::On)
	{
		return false;
	}

	m_engineState = EngineState::On;

	return true;
}

bool CCar::TurnEngineOff()
{
	if (m_engineState != EngineState::On)
	{
		return false;	
	}

	if (m_gear != Gear::Neutral)
	{
		return false;
	}

	if (m_speed != 0)
	{
		return false;
	}

	m_engineState = EngineState::Off;

	return true;
}

bool CCar::SetGear(int gear)
{
	if (!IsGearAllowed(Gear(gear)))
	{
		return false;
	}

	switch (gear)
	{
	case -1:
		m_gear = Gear::Reverse;
		break;
	case 0:
		m_gear = Gear::Neutral;
		break;
	case 1:
		m_gear = Gear::First;
		break;
	case 2:
		m_gear = Gear::Second;
		break;
	case 3:
		m_gear = Gear::Third;
		break;
	case 4:
		m_gear = Gear::Fourth;
		break;
	case 5:
		m_gear = Gear::Fifth;
		break;
	default:
		return false;
	}

	return true;
}

bool CCar::SetSpeed(int speed)
{
	if (m_engineState == EngineState::Off)
	{
		return false;
	}

	if ((m_gear == Gear::Neutral) && (speed > m_speed))
	{
		return false;
	}

	if (!IsSpeedAllowed(speed))
	{
		return false;
	}

	m_speed = speed;

	SetDirection();

	return true;
}

std::string CCar::GetEngineState() const
{
	if (m_engineState == EngineState::On)
	{
		return "On";
	}

	return "Off";
}

std::string CCar::GetDirection() const
{
	if (m_direction == DrivingDirection::Backward)
	{
		return "Backward";
	}
	else if (m_direction == DrivingDirection::NotMoving)
	{
		return "Not moving";
	}

	return "Forward";
}

int CCar::GetSpeed() const
{
	return m_speed;
}

int CCar::GetGear() const
{
	return int(m_gear);
}

bool CCar::IsSpeedAllowed(Speed speed)
{
	auto gearRange = SPEED_RANGES.find(m_gear);
	Speed minGearSpeed = gearRange->second.first;
	Speed maxGearSpeed = gearRange->second.second;

	if ((minGearSpeed <= speed) && (speed <= maxGearSpeed))
	{
		return true;
	}

	return false;
}

bool CCar::IsGearAllowed(Gear gear)
{
	if ((m_engineState == EngineState::Off) && (gear != Gear::Neutral))
	{
		return false;
	}

	if (gear == Gear::Reverse)
	{
		if (m_speed > 0)
		{
			return false;
		}
	}

	if (gear == Gear::First) 
	{
		if (((m_gear == Gear::Reverse) || (m_gear == Gear::Neutral)) && (m_speed > 0))
		{
			return false;
		}
	}

	auto gearRange = SPEED_RANGES.find(gear);

	if (gearRange == SPEED_RANGES.end())
	{
		return false;
	}

	Speed minGearSpeed = gearRange->second.first;
	Speed maxGearSpeed = gearRange->second.second;

	if ((m_speed < minGearSpeed) || (m_speed > maxGearSpeed))
	{
		return false;
	}

	return true;
}

void CCar::SetDirection()
{
	if (m_speed == 0)
	{
		m_direction = DrivingDirection::NotMoving;
	}
	else
	{
		if (m_gear == Gear::Reverse)
		{
			m_direction = DrivingDirection::Backward;
		}
		else if (m_gear != Gear::Neutral)
		{
			m_direction = DrivingDirection::Forward;
		}
	}
}