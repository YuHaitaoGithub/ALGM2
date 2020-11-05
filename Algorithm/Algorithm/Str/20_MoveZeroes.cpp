#include "..\Include\20_MoveZeroes.h"

void MoveZeroes(vector<int>& nums)
{
	int len = nums.size();
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
			nums.erase(nums.begin()+i--);
	}
	nums.insert(nums.end(), len - nums.size(), 0);
}