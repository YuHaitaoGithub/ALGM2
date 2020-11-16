#include"..\Include\04_IsPalindrome.h"
#include"stdio.h"

bool  IsPalindrome(int x)
{
	if (x < 0)return false;
	if (x == 0)return true;
	long long x1 = 0;
	int x2 = x;
	while (x2)
	{
		x1 = x1 * 10 + x2 % 10;
		x2 /= 10;
	}
	return x1 == x;
}