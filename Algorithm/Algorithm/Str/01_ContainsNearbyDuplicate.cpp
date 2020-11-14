#include <string>
#include <map>  
#include <iostream>
#include "..\Include\01_ContainsNearbyDuplicate.h"
using namespace std;


bool ContainsNearbyDuplicate(int* nums, int numsSize, int k)
{
	map<int, int>m;
	for (int i = 0; i < numsSize; i++)
	{
		if (m.count(nums[i]))
		{
			if (abs(m.at(nums[i]) - i) <= k)
				return true;
		}
		else
			m.insert(pair<int, int>(nums[i], i));
	}
	return false;
}

