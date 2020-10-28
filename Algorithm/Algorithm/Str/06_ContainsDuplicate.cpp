#include "..\Include\06_ContainsDuplicate.h"
#include <string>
#include <map>  
#include <iostream>

using namespace std;

bool ContainsDuplicate(int* nums, int numsSize)
{
	if (nums[0] == '\0')return false;
	map<int, int>m;//定义个容器m
	pair<map<int, int>::iterator, bool> Insert_Pair;
	for (int i = 0; i < numsSize; i++)
	{
		Insert_Pair = m.insert(pair<int, int>(nums[i], i));//判断是否为空
		if (!Insert_Pair.second)return true;
	}
	return false;
}