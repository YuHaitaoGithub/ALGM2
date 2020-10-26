#include "..\Include\06_ContainsDuplicate.h"

bool ContainsDuplicate(int* nums, int numsSize)
{
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] == nums[j])return true;
		}
	}

	return false;
}