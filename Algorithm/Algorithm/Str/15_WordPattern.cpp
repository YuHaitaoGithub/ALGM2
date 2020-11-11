#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\15_WordPattern.h"
#include "string.h"
#define MAXSIZE 500


bool WordPattern(char * pattern, char * s)
{
	int plen = strlen(pattern);
	char *sub[MAXSIZE];
	int rear = 0;
	sub[rear] = strtok(s, " ");
	while (sub[rear] != NULL)
	{
		rear++;
		sub[rear] = strtok(NULL, " ");//·Ö¶Î×Ö·û´®
	}
	if (plen != rear)
	{
		return false;
	}
	for (int i = 0; i < rear; i++)
	{
		for (int j = i + 1; j < rear; j++)//±È½Ï×Ö·û´®
		{
			if ((strcmp(sub[i], sub[j]) == 0 && pattern[i] != pattern[j]) ||
				(strcmp(sub[i], sub[j]) != 0 && pattern[i] == pattern[j]))
			{
				return false;
			}
		}
	}
	return true;

}
//
//bool WordPattern(string pattern, string s)
//{
//
//}

