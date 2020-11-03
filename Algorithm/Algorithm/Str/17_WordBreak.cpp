#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\17_WordBreak.h"
#include "String.h"
bool WordBreak(char * s, char ** wordDict, int wordDictSize)
{
	if ((NULL == s) && (NULL == wordDict))return true;
	if (NULL == s)return false;
	if (NULL == wordDict)return false;
	if (wordDictSize == 0)return false;
	char p1[100] = {};
	int tag = 0;
	int len = 0;
	for (int j = 0; j < wordDictSize; j++)
	{
		char *p = NULL;
		/*if (wordDict[j] == '\0')return false;*/
		p = strstr(s, wordDict[j]);
		if (NULL == p)
			tag++;
		else strcpy(p1 + len, wordDict[j]);
		len = strlen(p1);
	}
	if (tag == wordDictSize)return false;
	int len1 = strlen(s);
	int len2 = strlen(p1);
	if (len1 < len2)return false;
	int ret1 = 0;
	int ret2 = 0;
	for (int i = 0; i < len1; i++)
	{ 
		if (i < len2)
		{
			ret2 = p1[i] + ret2;
		}
		ret1 = s[i] + ret1;
	}
	return len1 > len2 ? ret1 > ret2:ret1 == ret2;

}

