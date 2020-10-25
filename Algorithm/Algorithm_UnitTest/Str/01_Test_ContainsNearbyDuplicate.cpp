#include "..\Statement.h"
#include "..\stdafx.h"
#include"..\..\Algorithm\Include\01_ContainsNearbyDuplicate.h"
#include "Windows.h"

#define MAX_LINE 100


bool Key_Juage(char *section, char *numsname, char *filename, char *keyname)
{
	char buf[100] = { '\0' };
	GetPrivateProfileStringA(section, numsname, NULL, buf, sizeof(buf), filename);
	int nums[MAX_LINE] = {};
	int times = 0;
	/*数组每个元素判断*/
	for (int i = 0; buf[i] != '\0'; i++)
	{
		if (!i)//判断第一位不为有效值的情况
		{
			while (buf[i] != '\0')
			{
				if ((buf[i] != ',') && (buf[i] != ' '))
				{
					if ((INT_MIN <= atoll(&buf[i])) && (atoll(&buf[i]) <= INT_MAX))//判断每个元素是否越界
						nums[times] = atoi(&buf[i]);
					else return false;
					times++;
					break;
				}
				else i++;
			}
		}
		else if (buf[i] == ',')//判断多位数时是不是首位
		{
			i = i + 1;
			if ((buf[i] != ',') && (buf[i] != ' '))
			{
				if ((atoll(&buf[i]) >= INT_MIN) && (atoll(&buf[i]) <= INT_MAX))
					nums[times] = atoi(&buf[i]);
				else return false;
				nums[times] = atoi(&buf[i]);//
				times++;
			}
		}
	}

	/*判断key的值是否越界*/
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
	int numsSize = times;
	bool r = ContainsNearbyDuplicate(nums, numsSize, l);//调用函数
	return r;
}




int Write_Juage(bool r, char *section, char *key1, char *filename)
{
	char *t = "ture";
	char *f = "false";
	if (r == true)WritePrivateProfileStringA(section, key1, t, filename);
	else WritePrivateProfileStringA(section, key1, f, filename);
	char buffer[100] = { '\0' };
	GetPrivateProfileStringA(section, key1, NULL, buffer, sizeof(buffer), filename);
	int tag = 0;
	if (buffer[0] == 't')tag = 1;
	else if (buffer[0] == 'f')tag = 0;
	else tag = -1;
	return tag;
}
