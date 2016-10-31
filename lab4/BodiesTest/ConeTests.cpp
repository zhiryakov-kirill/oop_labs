#include "stdafx.h"
#include "../Bodies/Cone.h"

struct ConeFixture
{
	CCone cone = CCone(2, 3, 8920);
};

BOOST_FIXTURE_TEST_SUITE(Cone, ConeFixture)

BOOST_AUTO_TEST_CASE(ConeHasRadius)
{
	BOOST_CHECK_EQUAL(cone.GetRadius(), 2);
}

BOOST_AUTO_TEST_CASE(ConeHasHeight)
{
	BOOST_CHECK_EQUAL(cone.GetHeight(), 3);
}

BOOST_AUTO_TEST_CASE(ConeHasVolume)
{
	const double EXPECTED_VOLUME = (M_PI * pow(cone.GetRadius(), 2) * cone.GetHeight()) / 3;
	BOOST_CHECK_EQUAL(cone.GetVolume(), EXPECTED_VOLUME);
	CBody & coneAsBody = cone;
	BOOST_CHECK_EQUAL(coneAsBody.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(ConeHasMass)
{
	BOOST_CHECK_EQUAL(cone.GetMass(), cone.GetVolume() * cone.GetDensity());
}

BOOST_AUTO_TEST_CASE(HasInformation)
{
	const std::string info = cone.GetInformation();
	std::ostringstream out;
	out << "Cone: " << std::endl << "Radius: " << cone.GetRadius() << " Height: " << cone.GetHeight();
	out << " Density: " << cone.GetDensity() << " Volume: " << cone.GetVolume() << " Massa: " << cone.GetMass() << std::endl;
	BOOST_CHECK_EQUAL(out.str(), info);
}

BOOST_AUTO_TEST_SUITE_END();