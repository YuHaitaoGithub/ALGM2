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
//bool WordPattern(char * pattern, char * s)
//{
//	int plen = strlen(pattern);
//	int slen = strlen(s);
//	if (plen == 0 && slen == 0)
//		return true;
//	if (plen == 0 || slen == 0)
//		return false;
//	vector<string>_s;
//	char *p = NULL;
//	int value = 0;
//	p = strtok(s, " ");
//	_s.push_back(p);
//	p = strtok(NULL, " ");
//	while (p != NULL)
//	{
//		_s.push_back(p);
//		p = strtok(NULL, " ");
//	}
//	map<char, string>m;
//	set<string>se;
//	m.insert(pair<char,string>(pattern[0], _s[0]));
//	se.insert(_s[0]);
//	for (int i = 1; i < plen; i++)
//	{
//		if (m.count(pattern[i]))
//		{
//			if (m[pattern[i]] != _s[i])
//				return false;
//		}
//		else
//		{
//			if (!se.insert(_s[i]).second)
//				return false;
//			else
//				m.insert(pair<char, string>(pattern[i], _s[i]));
//		}
//	}
//	return true;
//
//}

