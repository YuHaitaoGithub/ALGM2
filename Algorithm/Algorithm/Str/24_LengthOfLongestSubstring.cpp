#include "..\Include\24_LengthOfLongestSubstring.h"
#include "string.h"

#define MAX_LEN(a,b)  (a > b ? a : b)


int LengthOfLongestSubstring(char * s)
{
	if (s == NULL)return 0;
	int len = strlen(s);
	if (!len)return 0;
	int max_lenth = 1;
	if (len == 1)return len;
	int k = 0;
	for (int i = 1; i < len; i++)
	{
		for (int j = i; j > k; j--)
		{
			if (s[i] != s[j - 1])
				max_lenth = MAX_LEN(max_lenth, i - j + 2);
			else
				k = j;
		}
	}
	return max_lenth;
}