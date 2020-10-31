#include "..\Include\12_IsValid.h"
#include "string.h"
bool IsValid(char *s)
{
	int tag1 = 0;
	int tag2 = 0;
	int tag3 = 0;
	int k1 = 0;
	int k2 = 0;
	int k3 = 0;
	int v = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '(') && (tag1 == 0))
		{ 
			tag1 = 1;
			k1 = 1;
		}
		if ((s[++i] != ' ') && (tag1 == 1))
		{
			if (s[i] == ')')
			{
				k1=4; tag1 = 0;
			}
			else k1 = 1;
		}
		if ((tag1 == 0) && (s[i+1] == ')'))k1 = 1;
		if ((s[i] == '(') || (s[i] == ')'))v = 1;
	}
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '{') && (tag2 == 0))
		{
			tag2 = 1; k2 = 1;
		}
		if ((s[++i] != ' ') && (tag2 == 1))
		{
			if (s[i] == '}')
			{
				k2 = 4; tag2 = 0;
			}
			else k2 = 1;
		}
		if ((tag2 == 0) && (s[i+1] == '}'))k2 = 1;
	}
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '[') && (tag3 == 0)){
			tag3 = 1; k3 = 1;
		}
		if ((s[++i] != ' ') && (tag3 == 1))
		{
			if (s[i] == ']')
			{
				k3=4; tag3 = 0;
			}
			else k3 = 1;
		}
		if ((tag3 == 0) && (s[i+1] == ']'))k3 = 1;
	}
	return !(((k1 + k2 + k3) >= 0) && ((k1 + k2 + k3) <= 3));

	
	
}