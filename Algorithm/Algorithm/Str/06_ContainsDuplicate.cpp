#include "..\Include\06_ContainsDuplicate.h"
#include <set>  

using namespace std;

bool ContainsDuplicate(int* nums, int numsSize)
{
	if (nums[0] == '\0')return false;
	set<int>s;
	for (int i = 0; i < numsSize; i++)
	{
		if (s.count(nums[i]))
			return true;
		else
			s.insert(nums[i]);
	}
	return false;
}