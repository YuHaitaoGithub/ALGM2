#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\21_Reverse.h"
#include "stdio.h"
#include "math.h"
int Reverse(int x)
{
	char nums[13] = {};
	char *max = "2147483647";
	char *min = "2147483648";
	int symbol = 1;
	int len = sprintf(nums, "%d", x);
	if (len == 0)return 0;
	int j = 0;
	if (nums[0] == '-')
	{
		if (len == 1)return 0;
		if (len == 2)return x;
		j = len;
		symbol = -1;
	}
	else
	{
		if (len == 1)return x;
		j = len;
	}
	char *p = symbol == 1 ? max : min;
	if ((j == 10&&symbol == 1)||(j == 11&&symbol == -1))
	{
		for (int x = j -1; x >= 0; x--)
		{
			if (nums[x] - '0' > p[j-x-1] - '0')
				return 0;
			if (nums[x] - '0' < p[j - x - 1] - '0')
				break;
		}
	}
	int ret = 0;
	if (symbol == -1)
	{
		j--;
		for (int k = j; k > 0; k--)
		{
			ret = (int)pow(10.0, k - 1) * ((symbol)*(nums[k] - '0')) + ret;
		}
		return ret;
	}
	else {
		for (int k = j; k > 0; k--)
		{
			ret = (int)pow(10.0, k - 1) * ((symbol)*(nums[k-1] - '0')) + ret;
		}
		return ret;
	}

}