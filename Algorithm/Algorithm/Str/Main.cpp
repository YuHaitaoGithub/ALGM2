#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\02_ExcelSheetColumnTitle.h"
#include "Windows.h"
#include "stdio.h"
#define MAX_LINE 100



void main()
{
	/*int nums[4] = {1,2,3,1};
	int num = 4;
	printf("%d\n", ContainsDuplicate(nums,num));*/
	int a = 0;
	char *vaule;
	while (scanf_s("%d", &a))
	{		
		vaule = ExcelSheetColumnTitle(a);
		printf("%s\n", vaule);
    }

}