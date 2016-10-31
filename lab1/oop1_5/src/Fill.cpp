// Fill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FillMap.h"

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc == 3)
	{
		try
		{
			CFillMap map(argv[1]);
			map.FillMap();
			map.PrintMap(argv[2]);
			return 0;
		}
		catch (std::runtime_error const& e)
		{
			(void)e;
			puts("Input file open error");
			return 1;
		}
	}
	else
	{
		assert(argc > 0);
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		return 2;
	}
}
