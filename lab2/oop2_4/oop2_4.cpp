// oop2_4.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include "PrimeNumbers.h"
int const maxNumber = 100000000;
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Error. No arguments\n");
		return 0;
	}
	int upperBound = atoi(argv[1]);
	if (upperBound > maxNumber)
	{
		cout << "maxNumber is higher then " << maxNumber << endl;
		return 0;
	}
	set<int> primes = GeneratePrimeNumbersSet(upperBound); 

	for (int x : primes)
	{
		cout << x << " ";
	}
	return 0;
}

