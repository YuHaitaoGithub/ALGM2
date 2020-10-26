#include "..\Include\06_ContainsDuplicate.h"
#include "stdio.h"

bool ContainsDuplicate(int* nums, int numsSize)
{
	if (nums == NULL)return false;
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] == nums[j])return true;
		}
	}

	return false;
}