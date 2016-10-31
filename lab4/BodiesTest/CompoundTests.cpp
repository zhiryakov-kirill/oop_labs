#include "stdafx.h"
#include "../Bodies/Sphere.h"
#include "../Bodies/Parallelepiped.h"
#include "../Bodies/Cone.h"
#include "../Bodies/Cylinder.h"
#include "../Bodies/Compound.h"

using namespace std;

struct CompoundFixture
{
	CSphere sphere = CSphere(5, 1025);
	CParallelepiped parallelepiped = CParallelepiped(2, 3, 4, 8920);
	CCone cone = CCone(2, 3, 5023);
	CCylinder cylinder = CCylinder(2, 3, 8920);
	CCompound compound;
};

BOOST_FIXTURE_TEST_SUITE(Compound, CompoundFixture)

BOOST_AUTO_TEST_CASE(AddBody)
{
	compound.Add(make_shared<CSphere>(sphere));
	BOOST_CHECK_EQUAL(compound.GetVolume(), sphere.GetVolume());
	BOOST_CHECK_EQUAL(compound.GetDensity(), sphere.GetDensity());
	BOOST_CHECK_EQUAL(compound.GetMass(), sphere.GetMass());
}

BOOST_AUTO_TEST_CASE(AddBodies)
{
	compound.Add(make_shared<CSphere>(sphere));
	compound.Add(make_shared<CParallelepiped>(parallelepiped));
	compound.Add(make_shared<CCone>(cone));
	compound.Add(make_shared<CCylinder>(cylinder));

	double mass = sphere.GetMass() + parallelepiped.GetMass() + cylinder.GetMass() + cone.GetMass();
	double volume = sphere.GetVolume() + parallelepiped.GetVolume() + cylinder.GetVolume() + cone.GetVolume();
	
	BOOST_CHECK_EQUAL(compound.GetVolume(), volume);
	BOOST_CHECK_EQUAL(compound.GetDensity(), mass / volume);
	BOOST_CHECK_EQUAL(compound.GetMass(), mass);
}

BOOST_AUTO_TEST_CASE(AddCompoundInCompound)
{
	shared_ptr<CCompound> compound(new CCompound());
	BOOST_CHECK_EQUAL(compound->Add(compound), false);
}

BOOST_AUTO_TEST_CASE(AddCompoundToItselfChained)
{
	shared_ptr<CCompound> compound1(new CCompound());
	shared_ptr<CCompound> compound2(new CCompound());

	compound2->Add(shared_ptr<CParallelepiped>(new CParallelepiped(10, 3.6, 6, 40)));
	BOOST_CHECK_EQUAL(compound1->Add(compound2), true);
	BOOST_CHECK_EQUAL(compound2->Add(compound1), false);
}

BOOST_AUTO_TEST_CASE(HasInformation)
{
	const std::string info = compound.GetInformation();
	std::ostringstream out;
	out << "Compound: " << std::endl << " Density: " << compound.GetDensity() << " Mass: " << compound.GetMass() << " Volume: " << compound.GetVolume();
	
	BOOST_CHECK_EQUAL(out.str(), info);
}

BOOST_AUTO_TEST_SUITE_END();
