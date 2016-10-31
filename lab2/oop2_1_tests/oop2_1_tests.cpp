// task1_tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../oop2_1/ProcessVector.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_CASE(VectorWithOnePositiveElement)
{
	vector<double> numbers = { -1, 3 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { 1, -3 }));
}

BOOST_AUTO_TEST_CASE(VectorWithSeveralPositiveElements)
{
	vector<double> numbers = { 4, 5, 2, 3 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { (4 * 2), (5 * 2), (2 * 2), (3 * 2) }));
}