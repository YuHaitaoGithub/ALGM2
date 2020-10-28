#include "..\Statement.h"
#include "..\stdafx.h"

int Read_Num(char *section,char *keyname,char *filename)
{
	char key[20] = { '\0' };//
	int l = 0;
	int j = 0;
	GetPrivateProfileStringA(section, keyname, NULL, key, 20, filename);
	while (key[j] != '\0')
	{
		if ((key[j] != ',') && (key[j] != ' '))
		{
			l = atoi(&key[j]);
			break;
		}
		j++;
	}
	return l;
}

	
	

