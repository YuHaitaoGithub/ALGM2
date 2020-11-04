#include "..\Include\19_MySqrt.h"


int MySqrt(int x)
{
	if (x <= 0)return 0;
	unsigned int ret = 0;
	unsigned int i = 0;
	for (; ret < x; i++)
	{
		ret = i * i;
	}
	if (ret == x)
		return i - 1;
	else
		return i - 2;
}