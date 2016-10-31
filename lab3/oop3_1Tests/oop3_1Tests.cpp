// oop3_1Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../oop3_1/Car.h"

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

BOOST_AUTO_TEST_CASE(EngineOffByDefault)
{
	BOOST_CHECK_EQUAL(car.IsTurnedOn(), false);
}

BOOST_AUTO_TEST_CASE(TurnOnEngine)
{
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.IsTurnedOn(), true);
}

BOOST_AUTO_TEST_CASE(TurnOffEngine)
{
	car.TurnOnEngine();
	car.TurnOffEngine();
	BOOST_CHECK_EQUAL(car.IsTurnedOn(), false);
}

BOOST_AUTO_TEST_CASE(NeutralGearByDefault)
{
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
}

BOOST_AUTO_TEST_CASE(TurnOnEngineTwiceProduceFalse)
{
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), false);
}

BOOST_AUTO_TEST_CASE(TurnOffEngineTwiceProduceFalse)
{
	car.TurnOnEngine();
	car.TurnOffEngine();
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), false);
}

BOOST_AUTO_TEST_CASE(SetRearwardGear)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK_EQUAL(car.GetGear(), -1);
}

BOOST_AUTO_TEST_CASE(CanSetForwardGear)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK_EQUAL(car.GetGear(), 1);
}

BOOST_AUTO_TEST_CASE(GearRangeCheckWorks)
{
	car.TurnOnEngine();
	BOOST_CHECK(!(car.SetGear(-2)));
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(!(car.SetGear(6)));
}

BOOST_AUTO_TEST_CASE(CanRideBack)
{
	car.TurnOnEngine();
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(car.SetSpeed(10));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 10);
}

BOOST_AUTO_TEST_CASE(CanRideForward)
{
	car.TurnOnEngine();
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 20);
}

BOOST_AUTO_TEST_CASE(CanRideBackStopAndTurnOff)
{
	car.TurnOnEngine();
	car.SetGear(-1);
	car.SetSpeed(10);
	car.SetGear(0);
	car.SetSpeed(0);
	BOOST_CHECK(car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(CanRideForwardStopAndTurnOff)
{
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(20);
	car.SetGear(2);
	car.SetSpeed(40);
	car.SetGear(0);
	car.SetSpeed(0);
	BOOST_CHECK(car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(CanSwitchOntoNeutralWhenOff)
{
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK_EQUAL(car.GetGear(), 0);

	BOOST_CHECK(!(car.SetGear(-1)));
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
	
	BOOST_CHECK(!(car.SetGear(1)));
	BOOST_CHECK_EQUAL(car.GetGear(), 0);

}

BOOST_AUTO_TEST_CASE(NeutralGearSlowdownOnly)
{
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(30);
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(!(car.SetSpeed(31)));
	BOOST_CHECK(car.SetSpeed(30));
	BOOST_CHECK(car.SetSpeed(29));
	BOOST_CHECK(!(car.SetSpeed(30)));
}

BOOST_AUTO_TEST_CASE(NoForwardGearWhileMovingBackward)
{
	car.TurnOnEngine();
	car.SetGear(-1);
	car.SetSpeed(10);
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(!(car.SetGear(1)));
}

BOOST_AUTO_TEST_CASE(CarCanNotSwitchGearWithBackOnForwardWhileSpeedNoZero)
{
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(20);

	BOOST_CHECK(!car.SetGear(-1));
	BOOST_CHECK_EQUAL(car.GetGear(), 1);

	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(!car.SetGear(-1));
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
	
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK_EQUAL(car.GetGear(), -1);
	BOOST_CHECK(car.TurnOffEngine());
}

BOOST_AUTO_TEST_SUITE_END()