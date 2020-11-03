#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 1024
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Algm13_Test()
{
	char *filename = "..\\Algorithm\\Config\\13_MyAtoi.ini";
	char *keyname = "Input";
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

		char buff[200] = {};
		GetPrivateProfileStringA(section, keyname, NULL, buff, 200, filename);

		int f_ret = MyAtoi(buff);

		int ret = GetPrivateProfileIntA(section, key2, -1, filename);

		Assert::AreEqual(f_ret, ret);

		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}


}