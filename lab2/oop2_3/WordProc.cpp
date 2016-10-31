#include "stdafx.h"
#include "WordProc.h"

using namespace std;

void CountWords(string InputStr, StrIntMap& Words)
{
	string TmpStr;
	for (int i = 0; i < InputStr.size(); i++)
	{
		if (InputStr[i] == '\n' || InputStr[i] == ' ' || InputStr[i] == '\t')
		{
			++Words[TmpStr];
			TmpStr = "";
		}
		else
		{
			TmpStr += InputStr[i];
		}
	}
	if (TmpStr.size() > 0)
	{
		++Words[TmpStr];
	}
}