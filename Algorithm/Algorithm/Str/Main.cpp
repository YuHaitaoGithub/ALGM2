#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\12_IsValid.h"
#include "Windows.h"
#include "stdio.h"
#include "malloc.h"




void main()
{
	/*while (1)
	{
		char s[100] = {};
		gets(s);
		printf("%d\n", IsValid(s));
	}*/
	while (1)
	{
		char s[100] = {};
		gets(s);
		printf("%d\n",IsValid(s));
	}
	/*int nums[10] = {5,6,6,5,4,4,2,3,3};
	int numsize = 9;
	printf("%d\n", SingleNumber(nums, numsize));*/
}