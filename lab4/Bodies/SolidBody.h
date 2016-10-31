#pragma once
#include "Body.h"
#include <string>
class CSolidBody : public CBody
{
public:
	CSolidBody(double density);
	~CSolidBody(); 

	virtual double GetDensity() const override final;

	virtual double GetMass() const override final;

	//std::string GetInformation() const override;

private:
	double m_density;
};

