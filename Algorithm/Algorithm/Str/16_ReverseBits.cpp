#include "..\Include\16_ReverseBits.h"


uint32_t ReverseBits(uint32_t n)
{
	n = ((n & 0x55555555) << 1) | ((n & 0xaaaaaaaa) >> 1);
	n = ((n & 0x33333333) << 2) | ((n & 0xcccccccc) >> 2);
	n = ((n & 0x0f0f0f0f) << 4) | ((n & 0xf0f0f0f0) >> 4);
	n = ((n & 0x00ff00ff) << 8) | ((n & 0xff00ff00) >> 8);
	n = ((n & 0x0000ffff) << 16) | ((n & 0xffff0000) >> 16);
	return n;
}

//uint32_t ReverseBits(uint32_t n)
//{
//	uint32_t ret = 0;
//	int vaule = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (n&((uint32_t)1 << i))
//			vaule = 1;
//		else 
//			vaule = 0;
//		ret = ret + vaule * ((uint32_t)1 << (31 - i));
//	}
//	return ret;
//}

//uint32_t ReverseBits(uint32_t n)
//{
//	uint32_t x = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		x = (((n >> i) & 1) << (31 - i)) | x;
//	}
//	return x;
//}

