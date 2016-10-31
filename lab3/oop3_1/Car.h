#pragma once
class CCar
{
public:
	CCar();
	~CCar();
	bool TurnOnEngine();
	bool IsTurnedOn() const;
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	int GetGear() const;
	int GetSpeed() const;
	bool IsStopped() const;
	int GetDirection()const;
private:
	bool IsSpeedInGearLimits(int gear, int speed) const;
private:
	bool m_isEngineOn;
	int m_gear;
	int m_speed;
	static const int s_speedLimits[5][2];
};
