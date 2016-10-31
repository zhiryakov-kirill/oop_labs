// Flipbyte.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define NUMBER_TYPE_BIT_DEPTH 8
typedef uint8_t NumberType;
const NumberType NUMBER_TYPE_MAX = UINT8_MAX;
const NumberType NUMBER_TYPE_LOWEST_BIT = 1;
const NumberType NUMBER_TYPE_HIGHEST_BIT = (1 << (NUMBER_TYPE_BIT_DEPTH - 1));

NumberType FlipNumber(NumberType num)
{
	NumberType readMask = NUMBER_TYPE_LOWEST_BIT;
	NumberType writeMask = NUMBER_TYPE_HIGHEST_BIT;
	NumberType result = 0;

	while (readMask)
	{
		if (readMask & num)
		{
			result |= writeMask;
		}

		readMask <<= 1;
		writeMask >>= 1;
		assert((readMask == 0) == (writeMask == 0));
	}

	return result;
}

NumberType ParseNumberStr(const char str[])
{
	int strNum = std::stoi(str);

	if (strNum >= 0 && strNum <= NUMBER_TYPE_MAX)
	{
		return strNum;
	}
	else
	{
		throw std::out_of_range("ParseNumberStr argument number is out of range");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc == 2)
	{
		try
		{
			printf("%d\n", FlipNumber(ParseNumberStr(argv[1])));
			return 0;
		}
		catch (std::invalid_argument const& e)
		{
			(void)e;
			puts("Incorrect input byte format");
			return 1;
		}
		catch (std::out_of_range const& e)
		{
			(void)e;
			puts("Input byte is out of range");
			return 2;
		}
	}
	else
	{
		assert(argc > 0);
		printf("Usage: %s <input byte>\n", argv[0]);
		return 3;
	}
}
