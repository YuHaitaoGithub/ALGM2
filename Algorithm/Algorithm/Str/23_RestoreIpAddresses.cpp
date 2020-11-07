#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\23_RestoreIpAddresses.h"
#include "malloc.h"
#include"stdio.h"
#include"string.h"

void dsf(char *s, int *returnSize, int number, char **res, char *temp,int index,int len)
{
	if (number == 4)
	{
		res[*returnSize] = (char*)malloc((len + 4)*sizeof(char));
		temp[index + number - 1] = '\0';
		strcpy(res[*returnSize], temp);
		*returnSize = *returnSize + 1;
		return;
	}
	if ((len - index - 1<= (3 - number) * 3) && (len - index -  1>= 3 - number))
	{
		temp[index + number] = s[index];
		temp[index + number + 1] = '.';
		dsf(s, returnSize, number+1, res, temp, index+1, len);
	}

	if ((len - index - 2 <= (3 - number) * 3) && (len - index - 2 >= 3 - number) && s[index] != '0')
	{
		temp[index + number] = s[index];
		temp[index + number+1] = s[index+1];
		temp[index + number+2] = '.';
		dsf(s, returnSize, number + 1, res, temp, index + 2, len);
	}

	if ((len - index - 3 <= (3 - number) * 3 )
		&&( len - index - 3 >= (3 - number)) && (s[index] != '0' )
		&& (((s[index] - '0') * 100) + ((s[index + 1] - '0') * 10) + s[index + 2] - '0' <= 255))
	{
		temp[index + number] = s[index];
		temp[index + number + 1] = s[index + 1];
		temp[index + number + 2] = s[index + 2];
		temp[index + number + 3] = '.';
		dsf(s, returnSize, number + 1, res, temp, index + 3, len);
	}


}

char **RestoreIpAddresses(char * s, int *returnSize)
{
	if (s == NULL)
		return NULL;
	int len = strlen(s);
	if (len > 12||len<4)return NULL;
	char** res = (char**)malloc(sizeof(char*) * 100);
	if (res == NULL)
		return false;
	int index = 0;
	int number = 0;
	char temp[50] = {};
	dsf(s, returnSize, number, res, temp,index,len);
	//free(temp);
	return res;
}

