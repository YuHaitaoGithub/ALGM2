#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\17_WordBreak.h"
#include "String.h"
#include "malloc.h"
#include<String>


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
			dp[i] = (dp[k] && !strncmp(s + k, wordDict[j], wlen));
			if (dp[i])
				break;
		}
	bool ret_dp = dp[slen];
	
	free(dp);
	dp = NULL;
	return ret_dp;

}

//bool WordBreak(string s, vector<string>& wordDict)
//{
//	if (s.size() == 0 && wordDict.size() == 0)
//		return false;
//	vector<bool>dp(s.size() + 1, false);
//	dp[0] = true;
//	set<string>my_set(wordDict.begin(), wordDict.end());
//	for (int i = 1; i <= s.size(); ++i)
//	{
//		for (int j = i - 1; j >= 0; --j)
//		{
//			dp[i] = dp[j] && my_set.count(s.substr(j, i - j));
//			if (dp[i])
//				break;
//		}
//	}
//	return dp.back();
//}