#include "..\Include\16_ReverseBits.h"




uint32_t ReverseBits(uint32_t n)
{
	uint32_t ret = 0;
	int vaule = 0;
	for (int i = 0; i < 32; i++)
	{
		if (n&((uint32_t)1 << i))
			vaule = 1;
		else 
			vaule = 0;
		ret = ret + vaule * ((uint32_t)1 << (31 - i));
	}
	return ret;
}