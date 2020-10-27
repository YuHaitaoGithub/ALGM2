#include "..\Statement.h"
#include "..\stdafx.h"
#include "Windows.h"

int Num3_Juage(char *section, char *keyname, char *filename)
{
	char key[20] = { '\0' };//
	int l = 0;
	GetPrivateProfileStringA(section, keyname, NULL, key, 20, filename);
	int j = 0;
	int t = 0;
	while (key[j] != '\0')
	{
		if ((key[j] != ',') && (key[j] != ' '))
		{
			if ((atoll(&key[j]) >= INT_MIN) && (atoll(&key[j]) <= INT_MAX))
			{
				l = atoi(&key[j]);
			}
			else
			{
				l = 0;
			}
			break;
		}
		j++;
	}
	return l;
}