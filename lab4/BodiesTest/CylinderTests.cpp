#include "stdafx.h"
#include "../Bodies/Cylinder.h"

struct CylinderFixture
{
	CCylinder cylinder = CCylinder(2, 3, 8920);
};

BOOST_FIXTURE_TEST_SUITE(Cylinder, CylinderFixture)

BOOST_AUTO_TEST_CASE(ConeHasRadius)
{
	BOOST_CHECK_EQUAL(cylinder.GetRadius(), 2);
}

BOOST_AUTO_TEST_CASE(ConeHasHeight)
{
	BOOST_CHECK_EQUAL(cylinder.GetHeight(), 3);
}

BOOST_AUTO_TEST_CASE(ConeHasVolume)
{
	const double EXPECTED_VOLUME = M_PI * pow(cylinder.GetRadius(), 2) * cylinder.GetHeight();
	BOOST_CHECK_EQUAL(cylinder.GetVolume(), EXPECTED_VOLUME);
	CBody & cylinderAsBody = cylinder;
	BOOST_CHECK_EQUAL(cylinderAsBody.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(ConeHasMass)
{
	BOOST_CHECK_EQUAL(cylinder.GetMass(), cylinder.GetVolume() * cylinder.GetDensity());
}

BOOST_AUTO_TEST_CASE(HasInformation)
{
	const std::string info = cylinder.GetInformation();
	std::ostringstream out;
	out << "Cylinder: " << std::endl << "Radius: " << cylinder.GetRadius() << " Height: " << cylinder.GetHeight();
	out << " Density: " << cylinder.GetDensity() << " Volume: " << cylinder.GetVolume() << " Massa: " << cylinder.GetMass() << std::endl;
	BOOST_CHECK_EQUAL(out.str(), info);
}

BOOST_AUTO_TEST_SUITE_END();