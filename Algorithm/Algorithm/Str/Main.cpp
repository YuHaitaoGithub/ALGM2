#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\09_AddBinary.h"
#include "Windows.h"
#include "stdio.h"
#define MAX_LINE 100



void main()
{
	/*int nums[4] = {1,2,3,1};
	int num = 4;
	printf("%d\n", ContainsDuplicate(nums,num));*/
	char a[20] = {};
	char b[20] = {};
	char *vaule = NULL;
	gets(a);
	gets(b);
	vaule = AddBinary(a, b);
	printf("%s", vaule);

}