#include "..\Include\06_ContainsDuplicate.h"
#include <set>  

using namespace std;

bool ContainsDuplicate(int* nums, int numsSize)
{
	if (nums[0] == '\0')
		return false;
	set<int>my_set;
	for (int i = 0; i < numsSize; i++)
	{
		if (my_set.count(nums[i]))
			return true;
		else
			my_set.insert(nums[i]);
	}
	return false;
}