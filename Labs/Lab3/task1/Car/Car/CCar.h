#pragma once
#include <string>

using Speed = int;

enum class EngineState
{
	Off,
	On,
};

enum class DrivingDirection
{
	Backward,
	NotMoving,
	Forward,
};

enum class Gear
{
	Reverse = -1,
	Neutral,
	First,
	Second,
	Third,
	Fourth,
	Fifth,
};

class CCar
{
public:
	CCar();
	~CCar();
	bool TurnEngineOn();
	bool TurnEngineOff();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	EngineState m_engineState;
	DrivingDirection m_direction;
	Speed m_speed;
	Gear m_gear;

public:
	std::string GetEngineState() const;
	std::string GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;

private:
	bool IsSpeedAllowed(Speed speed);
	bool IsGearAllowed(Gear gear);
};
