#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 200

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Algm18_Test()
{
	char *filename = "..\\Algorithm\\Config\\18_PlusOne.ini";
	char *input = "Input";
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

		int In_buf[200] = {};
		char buf[200] = {};
		GetPrivateProfileStringA(section, input, NULL, buf, 200, filename);
		int digitsSize = 0;
		for (int i = 0; buf[i] != '\0'; i++)
			if (buf[i] != ',')
				In_buf[digitsSize++] = atoi(&buf[i]);
		
		int retSize = 0;
		int *returnSize = &retSize;
		int *ret = PlusOne(In_buf, digitsSize, returnSize);

		char out[200] = {};
		int out1[200] = {};
		int h = 0;
		GetPrivateProfileStringA(section, output, NULL, out, 200, filename);
		for (int i = 0; out[i] != '\0'; i++)
		{
			if (out[i] != ',')
				out1[h++] = atoi(&out[i]);
		}

		for (int u = 0; u < retSize; u++)
		{
			Assert::AreEqual(ret[u], out1[u]);
		}
		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}
}