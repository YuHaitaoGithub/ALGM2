#include"..\Include\04_IsPalindrome.h"
#include "string.h"
#define MAX_LEN 100

bool  IsPalindrome(int num)
{
	char vaule[MAX_LEN] = { '\0' };
	if (num < 0)return false;
	int i = 0;
	int tag = 0;
	while (num)
	{
		tag = num % 10;
		vaule[i] = (char)('0' + tag);
		i++;
		num = num / 10;
	}
	i = i - 1;
	int len = i / 2 + 1;
	for (int k = 0; k < len; k++)
	{
		if (vaule[i - k] != vaule[k])
			return false;
	}
	return true;
}