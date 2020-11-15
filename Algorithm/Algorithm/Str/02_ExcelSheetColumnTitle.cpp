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
		--n;
		vaule[i] = (char)('A' + n % 26);
		n /= 26;
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

/*string ExcelSheetColumnTitle(int n)
{
	string ret = "";
	if (n <= 0)
		return ret;
	while (n)
	{
		--n;
		ret.insert(ret.begin(), 'A' + n % 26);
		n /= 26;
	}
	return ret;
}*/