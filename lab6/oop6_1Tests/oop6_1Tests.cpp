// oop6_1Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../oop6_1/Solve3.h"

BOOST_AUTO_TEST_SUITE(Solve3Tests)

BOOST_AUTO_TEST_CASE(IfAEqualZeroReturnError)
{
	BOOST_CHECK_THROW(Solve3(0, 1, 2, 3), std::invalid_argument);
	BOOST_CHECK_NO_THROW(Solve3(1, 2, 3, 4));
}

BOOST_AUTO_TEST_CASE(DMoreZero)
{
	auto result = Solve3(1, 3, 4, 2);
	BOOST_CHECK(result.numRoots, 1);
	BOOST_CHECK(result.roots[0], -1);
}

BOOST_AUTO_TEST_CASE(DLessZero)
{
	//double a = 1, b = 6, c = 3, d = -10; // D < 0
	auto result = Solve3(1, 6, 3, -10);
	BOOST_CHECK(result.numRoots, 3);
	BOOST_CHECK(result.roots[0], -5);
	BOOST_CHECK(result.roots[1], -2);
	BOOST_CHECK(result.roots[2], 1);
}

BOOST_AUTO_TEST_CASE(DEqualZero)
{
	//double a = 1, b = 12, c = 36, d = 32; // D = 0
	auto result = Solve3(1, 12, 36, 35);
	BOOST_CHECK(result.numRoots, 2);
	BOOST_CHECK(result.roots[0], -8);
	BOOST_CHECK(result.roots[1], -2);
}
BOOST_AUTO_TEST_SUITE_END()