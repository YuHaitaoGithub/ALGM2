#include "..\Include\12_IsValid.h"
#include "string.h"

bool IsValid(char *s)
{
	int tag, j, k;
	k = tag = j = 0;
	int len = strlen(s);
	char a[7] = { '(', '{', '[', ')', '}', ']' };
	for (int i = 0; j < 3; i++)
	{
		if ((s[i] == a[j]) && (tag == 0))
		{ 
			tag = 1;k = 0;
		}
		if (s[i + 1] == a[j + 3])
		{
			if (tag == 1)
			{
				k++; tag = 0;
			}
			else k--;
		}
		if (i >= len - 1){
			j++; i = -1; tag = 0; //ÅĞ¶Ï±éÀúÊÇ·ñ½áÊø
		}
	}
	return k == 1;	
}
//bool IsValid(char *s)
//{
//	int len = strlen(s);
//	if (len == 0)return false;
//	if (len % 2 != 0)return false;
//	char arr[100] = {};
//	int arr2[100] = {};
//	int tag = -1;
//	for (int i = 0; i < len; i++)
//	{
//		if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
//		{
//			tag++; arr[tag] = s[i]; arr2[tag] = i;
//		}
//	}
//	if (tag == -1)return false;
//	int t = 0;
//	switch (arr[tag])
//	{
//	case '(':{if (s[arr2[tag] + 1] == ')')t = 1; else return false; }
//	case '{':{if (s[arr2[tag] + 1] == '}')t = 1; else return false; }
//	case '[':{if (s[arr2[tag] + 1] == ']')t = 1; else return false; }
//	}
//	if (tag > 0)tag--; else return true;
//	int t1, t2, t3;
//	t1 = t2 = t3 = 0;
//	for (int j = arr2[tag]; j < len; j++)
//	{
//		switch (arr[tag])
//		{
//		case '(':{if (s[j + 1] == ')')t1++; }
//		case '{':{if (s[j + 1] == '}')t2++; }
//		case '[':{if (s[j + 1] == ']')t3++; }
//		}
//		if (j == len){
//			tag--;
//			if (tag >= 0)j = --arr2[tag];
//			else break;
//		}
//	}
//
//	return tag == -1;
//}