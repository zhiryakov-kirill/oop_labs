// oop2_3.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include "WordProc.h"

using namespace std;

int main()
{
	StrIntMap Words;
	string InputStr;

	getline(cin, InputStr);
	CountWords(InputStr, Words);

	for (StrIntMap::iterator it = Words.begin(); it != Words.end(); ++it)
	{
		std::cout << it->first << " -> " << it->second << "\n";
	}
	return 0;
}