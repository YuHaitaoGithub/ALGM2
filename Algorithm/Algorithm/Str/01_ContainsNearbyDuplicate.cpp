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

//��ǰ�汾
//map<int, int>m;
//	map<int, int>::iterator iter;//�����������
//	pair<map<int, int>::iterator, bool> Insert_Pair;
//int tag = 0;
//for(int i = 0;i<numsSize;i++)
//{
	//if (m.insert(pair<int, int>(nums[i], i)));//�ж��Ƿ�Ϊ��
	//if (!Insert_Pair.second)
	//{
	//	iter = m.find(nums[i]);
	//	tag = (iter->second) >= i ? (iter->second) - i : i - (iter->second);
	//	return k >= tag ? true : false;
	//}
//return flase;
//}