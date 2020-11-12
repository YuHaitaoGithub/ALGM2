#include"..\Include\04_IsPalindrome.h"
#include "string.h"
//#define MAX_LEN 100


//bool  IsPalindrome(int x)
//{
//	char vaule[MAX_LEN] = { '\0' };
//	if (x < 0)return false;
//	if (x == 0)return true;
//	int i = 0;
//	int tag = 0;
//	while (x)
//	{
//		tag = x % 10;
//		vaule[i] = (char)('0' + tag);
//		i++;
//		x = x / 10;
//	}
//	i = i - 1;
//	int len = i / 2 + 1;
//	for (int k = 0; k < len; k++)
//	{
//		if (vaule[i - k] != vaule[k])
//			return false;
//	}
//	return true;
//}

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