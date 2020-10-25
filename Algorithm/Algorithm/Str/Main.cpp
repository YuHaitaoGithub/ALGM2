#include "..\Include\02_ExcelSheetColumnTitle.h"

#include "stdio.h"
void main()
{
	int num = 0;
	while (scanf_s("%d", &num))
	{
		printf("%s\n", ExcelSheetColumnTitle(num));
	}


}