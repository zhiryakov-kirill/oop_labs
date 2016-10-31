#include "stdafx.h"
#include "Cylinder.h"


CCylinder::CCylinder(double radius, double height, double density)
: CSolidBody(density)
, m_radius(radius)
, m_height(height)
{
}

CCylinder::~CCylinder()
{
}

double CCylinder::GetRadius() const
{
	return m_radius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return M_PI * pow(m_radius, 2) * m_height;
}

std::string CCylinder::GetInformation() const
{
	std::ostringstream out;
	out << "Cylinder: " << std::endl << "Radius: " << m_radius << " Height: " << m_height;
	out << " Density: " << GetDensity() << " Volume: " << GetVolume() << " Massa: " << GetMass() << std::endl;
	return out.str();
}