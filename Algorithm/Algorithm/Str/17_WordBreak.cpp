#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\17_WordBreak.h"
#include "String.h"
#include "malloc.h"

//"leetcode"能否break，可以拆分为："l"是否是单词表的单词、剩余子串能否break，
//"le"是否是单词表的单词、剩余子串能否break……以此类推。


bool WordBreak(char * s, char ** wordDict, int wordDictSize)
{
	if ((0 == strlen(s)) && (NULL == wordDict))
		return true;
	if ('\0' == s[0])
		return false;
	if (NULL == wordDict)
		return false;
	int slen = strlen(s);
	bool *dp = (bool*)calloc(slen+1, 1);
	dp[0] = true;
	int k = 0;
	for (int i = 1; i <= slen; i++)
		for (int j = 0; j < wordDictSize; j++)
		{
			int wlen = strlen(wordDict[j]);
			k = i - wlen;
			if (k < 0)
				continue;
			dp[i] = (dp[k] && !strncmp(s + k, wordDict[j], wlen)) || dp[i];
		}
	bool ret_dp = dp[slen];
	dp = NULL;
	free(dp);
	return ret_dp;

}

