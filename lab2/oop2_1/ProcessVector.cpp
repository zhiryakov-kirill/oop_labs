#include "stdafx.h"
#include "ProcessVector.h"
#include <algorithm>
#include <numeric>

using namespace std;

void ProcessVector(std::vector<double> & numbers)
{
	double MinElement = *min_element(numbers.begin(), numbers.end());
	transform(numbers.begin(), numbers.end(), numbers.begin(),
			[MinElement](double number){return number * MinElement; });
}