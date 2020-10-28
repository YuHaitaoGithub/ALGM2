#include <string>
#include <map>  
#include <iostream>
#include "..\Include\01_ContainsNearbyDuplicate.h"
using namespace std;


bool ContainsNearbyDuplicate(int* nums, int numsSize, int k)
{
	map<int, int>m;//定义个容器m
	map<int, int>::iterator iter;//定义个迭代器
	pair<map<int, int>::iterator, bool> Insert_Pair;
	int tag = 0;
	for (int i = 0; i < numsSize; i++)
	{
		Insert_Pair = m.insert(pair<int, int>(nums[i], i));//判断是否为空
		if (!Insert_Pair.second)
		{
			iter = m.find(nums[i]);
			tag = (iter->second) >= i ? (iter->second) - i : i - (iter->second);
			return k >= tag ? true : false;
		}
	}
	return false;
}