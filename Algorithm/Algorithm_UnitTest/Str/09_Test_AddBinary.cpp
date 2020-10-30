#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 1024
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Algm9_Test()
{
	char *filename = "..\\Algorithm\\Config\\09_AddBinary.ini";
	char *input1 = "Input1";
	char *input2 = "Input2";
	char *output = "Output";

	char section1[MAX_LINE] = { '\0' };//section1--该文件下所有节名保存数组
	int a = 0;
	GetPrivateProfileSectionNamesA(section1, MAX_LINE, filename);
	char section[MAX_LINE] = { '\0' };//保存单个节名数组
	int time = 0;
	while ((section1[a] != '\0') || (section1[a + 1] != '\0'))
	{
		for (int k = a; section1[k] != '\0'; k++)
			section[time++] = section1[k];


		char buf1[MAX_LINE] = {};
		char buffer1[MAX_LINE] = {};
		char buf2[MAX_LINE] = {};
		char buffer2[MAX_LINE] = {};
		GetPrivateProfileStringA(section, input1, NULL,buf1,MAX_LINE ,filename);
		GetPrivateProfileStringA(section, input2, NULL, buf2, MAX_LINE, filename);
		int i = 0;
		for (int t = 0; buf1[t] != '\0'; t++)
		{
			if (buf1[t] != '"')buffer1[i++] = buf1[t];
		}
		int j = 0;
		for (int t = 0; buf2[t] != '\0'; t++)
		{
			if (buf2[t] != '"')buffer2[j++] = buf2[t];
		}

		char *ret = AddBinary(buffer1, buffer2);

		memset(buf2, 0, sizeof(buf2));
		GetPrivateProfileStringA(section, output, NULL, buf2, MAX_LINE, filename);
		int lenth = strlen(ret) < strlen(buf2) ? strlen(ret) : strlen(buf2);
		j = 0;
		for (int x = 0; x < lenth; x++)
		{
			if (buf2[x] != '"')Assert::AreEqual(ret[j++], buf2[x]);
		}


		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}
}