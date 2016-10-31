#include "stdafx.h"
#include "RemoveSpaces.h"

using namespace std;

string RemoveExtraSpaces(const string &arg)
{
	string ResultString;
	bool WasSpace = false;
	bool WasFirstLitter = false;
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (arg[i] == ' ')
		{
			WasSpace = true;
		}
		else
		{
			if (WasSpace && WasFirstLitter)
			{
				ResultString += " ";
			}
			
			ResultString += arg[i];
			WasFirstLitter = true;
			WasSpace = false;
		}
	}
	return ResultString;
}
