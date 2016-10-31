#include "stdafx.h"
#include "Parallelepiped.h"
using namespace std;

CParallelepiped::CParallelepiped(double width, double height, double depth, double density)
	: CSolidBody(density)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
{
}

CParallelepiped::~CParallelepiped(void)
{
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetVolume() const
{
	return m_width * m_height * m_depth;
}

std::string CParallelepiped::GetInformation() const
{
	std::ostringstream out;
	out << "Parallelepiped: " << std::endl << "Width: " << m_width << " Height: " << m_height << " Depth: " << m_depth;
	out << " Density: " << GetDensity() << " Volume: " << GetVolume() << " Massa: " << GetMass() << std::endl;
	return out.str();
}