#include "..\Include\06_ContainsDuplicate.h"
#include <string>
#include <map>  
#include <iostream>

using namespace std;

bool ContainsDuplicate(int* nums, int numsSize)
{
	if (nums[0] == '\0')return false;
	map<int, int>m;//���������m
	pair<map<int, int>::iterator, bool> Insert_Pair;
	for (int i = 0; i < numsSize; i++)
	{
		Insert_Pair = m.insert(pair<int, int>(nums[i], i));//�ж��Ƿ�Ϊ��
		if (!Insert_Pair.second)return true;
	}
	return false;
}