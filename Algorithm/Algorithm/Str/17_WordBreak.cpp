#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\17_WordBreak.h"
#include "String.h"
bool WordBreak(char * s, char ** wordDict, int wordDictSize)
{
	if ((NULL == s) && (NULL == wordDict))return true;
	if (NULL == s)return false;
	if (NULL == wordDict)return false;
	char *p = NULL;
	for (int j = 0; j < wordDictSize; j++)
	{
		p = strstr(s, wordDict[j]);
		if (NULL != p)return true;
	}
	return false;

}