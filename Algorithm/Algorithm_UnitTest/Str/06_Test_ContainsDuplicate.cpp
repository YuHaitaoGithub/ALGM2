#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 200

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Algm6_Test()
{
	char *filename = "..\\Algorithm\\Config\\06_ContainsDuplicate.ini";
	char *numsname = "Input";
	char *key2 = "Output";

	char section1[MAX_LINE] = { '\0' };//section1--该文件下所有节名保存数组
	int a = 0;
	GetPrivateProfileSectionNamesA(section1, MAX_LINE, filename);
	char section[MAX_LINE] = { '\0' };//保存单个节名数组
	int time = 0;
	while ((section1[a] != '\0') || (section1[a + 1] != '\0'))
	{
		for (int k = a; section1[k] != '\0'; k++)
			section[time++] = section1[k];

		char buf[MAX_LINE] = { '\0' };
		GetPrivateProfileStringA(section, numsname, NULL, buf, sizeof(buf), filename);
		int nums[MAX_LINE] = {};
		int times = 0;
		/*数组每个元素判断*/
		for (int i = 0;((buf[i] != ']')&& (buf != NULL)); i++)
		{
			if (buf[i] != ' ')
				if (buf[i] == ',' || (buf[i] == '['))  nums[times++] = atoi(&buf[++i]);
		}
		bool r = ContainsDuplicate(nums, times);

		char buffer[100] = { '\0' };
		GetPrivateProfileStringA(section, key2, NULL, buffer, sizeof(buffer), filename);
		int tag = 0;
		if (buffer[0] == 't')tag = 1;
		else if (buffer[0] == 'f')tag = 0;

		Assert::AreEqual((int)r, tag);
		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}	
}