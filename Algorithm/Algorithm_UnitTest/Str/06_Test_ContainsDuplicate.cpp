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
	/*����ÿ��Ԫ���ж�*/
	for (int i = 0; buf[i] != '\0'; i++)
	{
		if (!i)//�жϵ�һλ��Ϊ��Чֵ�����
		{
			while (buf[i] != '\0')
			{
				if ((buf[i] != ',') && (buf[i] != ' ') && (buf[i] != '['))
				{
					if ((INT_MIN <= atoll(&buf[i])) && (atoll(&buf[i]) <= INT_MAX))//�ж�ÿ��Ԫ���Ƿ�Խ��
						nums[times] = atoi(&buf[i]);
					else return false;
					times++;
					break;
				}
				else i++;
			}
		}
		else if (buf[i] == ',')//�ж϶�λ��ʱ�ǲ�����λ
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