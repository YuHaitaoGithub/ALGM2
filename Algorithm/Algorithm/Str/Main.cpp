#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\22_Rotate.h"
#include "Windows.h"
#include "stdio.h"
#include "malloc.h"
#include <vector>
using namespace std;




void main()
{
	////int nums[] = { 0, 1, 0, 3, 12 };
	//vector<int> nums{ 0, 0,1 };
	//MoveZeroes(nums);
	//for (int i = 0; i < nums.size();i++)
	//printf("%d\n", nums[i]);


	int k[3] = { 1, 2, 3 };
	vector<int>k4{1, 2, 3};
		int k1 = 3;
		int k2 = 2;
		Rotate(k4,k2);
		for (int i = 0; i < k1; i++)
		{
			printf("%d,", k4[i]);
		}
	
	//while (1)
	//{
	//	char s[100] = {};
	//	gets(s);
	//	char *s2[] = {"cpp","add"};
	////	gets(s2);
	//	printf("%d\n", WordBreak(s, s2, 2));
	//}
	/*int nums[10] = {5,6,6,5,4,4,2,3,3};
	int numsize = 9;
	printf("%d\n", SingleNumber(nums, numsize));*/

	//int n[10] = {};
	//int p = 0;
	////int *pp = &p;
	//int d = 4;
	//while (1)
	//{ 
	//	for (int i = 0; i < d; i++)
	//	{
	//		scanf_s("%d", &n[i]);
	//	}
	//	int *pp = PlusOne(n, d, &p);
	//	for (int j = 0; j < p; j++)
	//	{
	//		printf("%d", pp[j]);
	//	}
	//}


}