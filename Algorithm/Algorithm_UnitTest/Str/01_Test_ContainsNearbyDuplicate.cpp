#include "..\Statement.h"
#include "..\stdafx.h"
#include"..\..\Algorithm\Include\01_ContainsNearbyDuplicate.h"
#include "Windows.h"

#define MAX_LINE 100

bool Read_Input(char *section, char *numsname, char *filename, char *keyname)
{
	/*读取数组元素*/
	char buf[MAX_LINE] = { '\0' };
	GetPrivateProfileStringA(section, numsname, NULL, buf, sizeof(buf), filename);
	int nums[MAX_LINE] = {};
	int times = 1;
	nums[0] = atoi(&buf[0]);
	for (int i = 1; buf[i] != '\0'; i++)
		if ((buf[i] == ',') && (buf[i + 1] != ' '))
			nums[times++] = atoi(&buf[++i]);
	/*读取key键值*/
	char key[20] = { '\0' };
	int l = 0;
	GetPrivateProfileStringA(section, keyname, NULL, key, 20, filename);
	l = atoi(&key[0]);
	int numsSize = times;
	bool r = ContainsNearbyDuplicate(nums, numsSize, l);//调用函数
	return r;
}



int Read_Output(char *section, char *key1, char *filename)
{
	char buffer[100] = { '\0' };
	GetPrivateProfileStringA(section, key1, NULL, buffer, sizeof(buffer), filename);
	int tag = 0;
	if (buffer[0] == 't')tag = 1;
	else if (buffer[0] == 'f')tag = 0;
	return tag;
}
