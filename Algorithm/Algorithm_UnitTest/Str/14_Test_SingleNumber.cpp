#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 200

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Algm14_Test()
{
	char *filename = "..\\Algorithm\\Config\\14_SingleNumber.ini";
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
		for (int i = 0; ((buf[i] != '\0') && (buf != NULL)); i++)
		{
			if (buf[i] != ',' || (buf[i] != ' '))  nums[times++] = atoi(&buf[i]);
		}
		int r = SingleNumber(nums, times);

		int tag = GetPrivateProfileIntA(section, key2, -1, filename);
		
		Assert::AreEqual(r, tag);

		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}
}