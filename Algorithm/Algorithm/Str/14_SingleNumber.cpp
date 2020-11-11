#include "..\Include\14_SingleNumber.h"
#include "stdio.h"
#include <set>

//int SingleNumber(int* nums, int numsSize)
//{
//	if (nums == NULL)return 0;
//	int a = nums[0];
//	if (numsSize > 0)
//		for (int i = 1; i < numsSize; i++)
//			a = a^nums[i];
//	return a;
//}

int SingleNumber(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	set<int>a;
	int i = 0;
	for (; i < nums.size(); i++)
	{
		if (a.count(nums.at(i)))
			a.erase(nums.at(i));
		else
			a.insert(nums.at(i));
	}
	return *a.begin();
}