#include "stdafx.h"
#include "Car.h"

const int CCar::s_speedLimits[5][2] = {{ 0, 30 }, 
									{ 20, 50 }, 
									{ 30, 60 }, 
									{ 40, 90 }, 
									{ 50, 150 }};

CCar::CCar()
:m_isEngineOn(false)
, m_gear(0)
, m_speed(0)
{
}

CCar::~CCar()
{
}

bool CCar::IsTurnedOn() const
{
	return m_isEngineOn;
}

bool CCar::TurnOnEngine()
{
	if (!m_isEngineOn)
	{
		m_isEngineOn = true;
		return m_isEngineOn;
	}
	else
		return false;

}

bool CCar::TurnOffEngine()
{
	if (!m_isEngineOn)
	{
		return false;
	}
	else
	{
		m_isEngineOn = false;
		return true;
	}
}

bool CCar::SetGear(int gear)
{
	if ((gear < -1) || (gear > 5))
	{
		return false;
	}
	if (!IsTurnedOn() && gear == 0)
	{
		m_gear = gear;
		return true;
	}
	if (!IsTurnedOn())
	{
		return false;
	}
	if (!IsSpeedInGearLimits(gear, m_speed))
	{
		return false;
	}

	if (gear == -1)
	{
		if (IsStopped())
		{
			m_gear = -1;
			return true;
		}
		return false;
	}

	if (GetGear() == -1 && !IsStopped())
	{
		if (gear == 0)
		{
			m_gear = gear;
			return true;
		}
		return false;
	}

	if (GetGear() == 0 && !IsStopped())
	{
		return false;
	}

	m_gear = gear;
	return true;
}

int CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

bool CCar::IsStopped() const
{
	return m_speed == 0;
}

bool CCar::IsSpeedInGearLimits(int gear, int speed) const
{
	if (gear == 0 && speed == 0)
	{
		return true;
	}

	if (gear == 0)
	{
		return ((speed >= 0) && (speed <= GetSpeed()));
	}

	if (gear == -1)
	{
		return (speed >= 0 && speed <= 20);
	}
	return ((speed >= s_speedLimits[gear - 1][0]) && (speed <= s_speedLimits[gear - 1][1]));
}

bool CCar::SetSpeed(int speed)
{
	if (!IsSpeedInGearLimits(m_gear, speed))
	{
		return false;
	}
	m_speed = speed;
	return true;
}

int CCar::GetDirection()const
{
	if (IsStopped())
	{
		return 0;
	}
	if (GetGear() >= 0 && !IsStopped())
	{
		return 1;
	}
	return -1;
}
