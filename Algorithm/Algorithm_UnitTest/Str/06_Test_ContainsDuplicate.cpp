#include "..\Statement.h"
#include "..\stdafx.h"
#include "Windows.h"
#define MAX_LINE 200

bool Nums_Juage(char *section, char *numsname, char *filename)
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
				if ((buf[i] != ',') && (buf[i] != ' ') && (buf[i] != '['))
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
			if ((buf[i] != ',') && (buf[i] != ' ') && (buf[i] != '['))
			{
				if ((atoll(&buf[i]) >= INT_MIN) && (atoll(&buf[i]) <= INT_MAX))
					nums[times] = atoi(&buf[i]);
				else return false;
				nums[times] = atoi(&buf[i]);//
				times++;
			}
		}
	}
	bool r = ContainsDuplicate(nums, times);
	return r;
}