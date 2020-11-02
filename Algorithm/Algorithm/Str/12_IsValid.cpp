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