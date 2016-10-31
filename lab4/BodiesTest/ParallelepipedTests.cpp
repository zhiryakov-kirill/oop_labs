#include "stdafx.h"
#include "../Bodies/Parallelepiped.h"

struct ParallelepipedFixture
{
	CParallelepiped parallelepiped = CParallelepiped(2, 3, 4, 8920);
};

BOOST_FIXTURE_TEST_SUITE(Parallelepiped, ParallelepipedFixture)

BOOST_AUTO_TEST_CASE(ParallelepipedHasWidth)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetWidth(), 2);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasHeight)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), 3);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasDensity)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetDensity(), 8920);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasVolume)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetVolume(), 2 * 3 * 4);
	CBody & parallelepipedAsBody = parallelepiped;
	BOOST_CHECK_EQUAL(parallelepipedAsBody.GetVolume(), 2 * 3 * 4);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasMass)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetMass(), parallelepiped.GetDensity() * parallelepiped.GetVolume());
}

BOOST_AUTO_TEST_CASE(HasInformation)
{
	const std::string info = parallelepiped.GetInformation();
	std::ostringstream out;
	out << "Parallelepiped: " << std::endl << "Width: " << parallelepiped.GetWidth() << " Height: " << parallelepiped.GetHeight() << " Depth: " << parallelepiped.GetDepth();
	out << " Density: " << parallelepiped.GetDensity() << " Volume: " << parallelepiped.GetVolume() << " Massa: " << parallelepiped.GetMass() << std::endl;
	BOOST_CHECK_EQUAL(out.str(), info);
}

BOOST_AUTO_TEST_SUITE_END();