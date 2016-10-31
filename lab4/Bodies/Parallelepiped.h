#pragma once
#include "SolidBody.h"

class CParallelepiped : public CSolidBody
{
public:
	CParallelepiped(double width, double height, double depth, double density);
	~CParallelepiped(void);

	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	// методы, переопредел€ющие методы базовых классов, рекомендуетс€ 
	// объ€вл€ть со спецификатором override
	double GetVolume() const override;
	std::string GetInformation() const override;

private:
	double m_width;
	double m_height;
	double m_depth;


};

