#include "..\Include\14_SingleNumber.h"

int SingleNumber(int* nums, int numsSize)
{
	int a = nums[0];
	if (numsSize > 0)
		for (int i = 1; i < numsSize; i++)
			a = a^nums[i];
	return a;
}