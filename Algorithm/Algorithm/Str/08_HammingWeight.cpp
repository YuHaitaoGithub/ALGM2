#include "..\Include\08_HammingWeight.h"

///*方法一循环取余数*/
//int HammingWeight(uint32_t n)
//{
//	if (n == 0)return 0;
//	int i = 0;
//	int times = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//			times++;
//		n = n / 2;
//	}
//	return times;
//
//}
#include <bitset>
#include <iostream>
using namespace std;

int HammingWeight(uint32_t n)
{
	cout << bitset<32>(n) << endl;
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	cout << bitset<32>(n) << endl;
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	cout << bitset<32>(n) << endl;
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	cout << bitset<32>(n) << endl;
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	cout << bitset<32>(n) << endl;
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	cout << bitset<32>(n) << endl;
	return n;
}
