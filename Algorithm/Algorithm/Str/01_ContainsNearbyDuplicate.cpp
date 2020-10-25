#include "stdio.h"
#include "..\Include\01_ContainsNearbyDuplicate.h"
bool ContainsNearbyDuplicate(int* nums, int numsSize, int k)
{
	if (numsSize <= k)//判断数组长度是否小于k
	{
		for (int i = 0; i < numsSize; i++)
		{
			for (int j = i + 1; j < numsSize; j++)
				if (nums[i] == nums[j])
					return true;
		}
	}
	else
	{
		int x = 0;
		int y = 0;
		for (x = 0; x < numsSize - k; x++)
		{
			for (y = x + 1; y <= x + k; y++)
			{
				if (nums[x] == nums[y])
					return true;
			}
		}
		for (x = numsSize - k; x < numsSize; x++)
		{
			for (y = x + 1; y<numsSize; y++)
				if (nums[x] == nums[y])
					return true;
		}
	}
	return false;
}