#include"..\Include\04_IsPalindrome.h"
#include "string.h"
#define MAX_LEN 100

bool  IsPalindrome(int num)
{
	char vaule[MAX_LEN] = { '\0' };
	char vaules[MAX_LEN] = { '\0' };
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
	int len = strlen(vaule) - 1;
	int j = 0;
	while (vaule[j] != '\0')
	{
		vaules[j] = vaule[len - j];
		j++;
	}
	int len1 = strlen(vaules);
	for (int k = 0; k < len1; k++)
	{
		if (vaules[k] == vaule[k]);
		else return false;
	}
	return true;
}