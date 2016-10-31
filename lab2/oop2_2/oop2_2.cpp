// oop2_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "RemoveSpaces.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string resultList;
	getline(cin, resultList);
	cout << RemoveExtraSpaces(resultList);
	
	return 0;
}
