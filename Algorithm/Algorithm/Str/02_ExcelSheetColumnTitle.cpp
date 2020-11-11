#include "..\Include\02_ExcelSheetColumnTitle.h"
#include "string.h"
#define MAX_LEN  20
char * ExcelSheetColumnTitle(int n)
{
	char vaule[MAX_LEN] = { '\0' };
	if (n <= 0)return vaule;
	int i = 0;
	int tag = 0;
	while (n)
	{
		tag = n % 26;
		if (tag)
		{
			vaule[i] = (char)('A' + (tag - 1));
			n = n / 26;
		}
		else
		{
			vaule[i] = (char)('A' + 25);
			n = (n - 1) / 26;
		}
		i++;
	}
	i--;
	char vaules[MAX_LEN] = { '\0' };
	vaules[0] = '"';
	for (int j = 0; j <= i; j++)
	{
		vaules[i - j + 1] = vaule[j];
	}
	vaules[strlen(vaules)] = '"';
	return vaules;
}