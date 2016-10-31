// oop2_4Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../oop2_4/PrimeNumbers.h"

using namespace std;

BOOST_AUTO_TEST_CASE(NoPrimeNumbers)
{
	set<int> primes = GeneratePrimeNumbersSet(1);
	BOOST_CHECK(primes.size() == 0);
}

BOOST_AUTO_TEST_CASE(NegativePrimeNumbers)
{
	set<int> primes = GeneratePrimeNumbersSet(-1);
	BOOST_CHECK(primes.size() == 0);
}

BOOST_AUTO_TEST_CASE(SomePrimeNumbers)
{
	set<int> primes = GeneratePrimeNumbersSet(15);
	set<int> rightSet = { 2, 3, 5, 7, 11, 13 };
	BOOST_CHECK(primes == rightSet);
}
