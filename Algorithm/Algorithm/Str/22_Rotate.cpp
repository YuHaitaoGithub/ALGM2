#include "..\Include\22_Rotate.h"

//方案一
//void Rotate(int* nums, int numsSize, int k)
//{
//	int t = 0;
//	int k1 = k % numsSize;	
//	if (k1 == 0)return;
//	while (k1--)
//	{
//		t = nums[numsSize - 1];
//		for (int i = numsSize - 1; i > 0; i--)
//		{
//			nums[i] = nums[i - 1];
//		}
//		nums[0] = t;
//	}
//}

//方案二
//void Rotate(vector<int>& nums, int k)
//{
//	if (k == 0 || k % nums.size() == 0)
//		return;
//	reverse(nums.begin(), nums.end());
//	reverse(nums.begin(), nums.begin() + (k % nums.size()));
//	reverse(nums.begin() + (k % nums.size()), nums.end());
//}

//方案三
void Rotate(vector<int>& nums, int k)
{
	if (k == 0 || k % nums.size() == 0)
		return;
	int k1 = k % nums.size();
	rotate(nums.begin(), nums.end() - k1, nums.end());
}
