#include "..\Include\21_Reverse.h"
#include "stdio.h"
#include"stdlib.h"


int Reverse(int x)
{
	int x1 = 0;
	while (x)
	{
		if (x1 > INT_MAX / 10 || x1 < INT_MIN / 10
			|| (x1 == INT_MAX / 10 && x1 % 10 > 7)
			|| (x1 == INT_MIN / 10 && x1 % 10 > 8))
			return 0;
		x1 = (x % 10) + x1 * 10;
		x = x / 10;
	}
	return x1;
}