#include "stdafx.h"
#include <vector>
#include <set>
#include <math.h>
#include "PrimeNumbers.h"

using namespace std;

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int> resultSet;
	if (upperBound > 1)
	{
		vector<bool> sieve(upperBound + 1, true);
		const int upperBoundSqrt = sqrt(upperBound);
		sieve[0] = false;
		sieve[1] = false;
		
		for (int i = 2; i <= upperBoundSqrt; i++)
		{
			if (sieve[i])
			{
				for (int j = i*i; j <= upperBound; j += i)
				{
					sieve[j] = false;
				}
			}
		}

		for (int i = 2; i <= upperBound; ++i)
		{
			if (sieve[i])
			{
				resultSet.insert(resultSet.end(), i);
			}
		}
	}
	return resultSet;
}
