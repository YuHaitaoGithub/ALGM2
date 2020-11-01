#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 1024
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Algm12_Test()
{

	char *filename = "..\\Algorithm\\Config\\12_IsValid.ini";
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

		char buf[200] = {};
		char buff[200] = {};
		int j = 0;
		GetPrivateProfileStringA(section, keyname,NULL,buf,200,filename);
		for (int i = 0; buf[i] != '\0'; i++)
		{
			if ((buf[i] != ',') || (buf[i] != '"'))buff[j++] = buf[i];
		}
		int f_ret = IsValid(buff);

		char buffer[100] = { '\0' };
		GetPrivateProfileStringA(section, key2, NULL, buffer, sizeof(buffer), filename);
		int tag = 0;
		if (buffer[0] == 't')tag = 1;

		Assert::AreEqual(f_ret, tag);

		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}

}