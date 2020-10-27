#include "..\Include\08_HammingWeight.h"

/*方法一循环取余数*/
int HammingWeight(uint32_t n)
{
	int i = 0;
	int times = 0;
	char num[100] = {};
	while (n)
	{
		num[i] = (char)('0' + (n % 2));
		if (num[i] == '1')times++;
		n = n / 2;
		i++;
	}
	return times;

}

/*方法二分段加和,效率高*/
/*  n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
return n;
*/