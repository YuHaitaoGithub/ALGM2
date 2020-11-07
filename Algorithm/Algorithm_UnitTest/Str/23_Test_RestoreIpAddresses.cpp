#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 200

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Algm23_Test()
{
	char *filename = "..\\Algorithm\\Config\\23_RestoreIpAddresses.ini";
	char *num = "Input";
	char *outnum = "Output";

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
		int h = 0;
		GetPrivateProfileStringA(section, num, NULL, buf, 200, filename);
		int *returnSize = &h;
		char **rt = RestoreIpAddresses(buf, returnSize);

		char rt2[200] = {};
		char rt3[200] = {};
		GetPrivateProfileStringA(section, outnum, NULL, rt2, 200, filename);
		for (int v = 0; rt2[v] != '\0'; v++)
			if ((rt2[v] != ',') && (rt2[v] != '"'))rt3[v] = rt2[v];
		int m = 0;
		for (int v = 0; v < *returnSize; v++)
		{
			for (int c = 0; rt[v][c] != '\0'; c++)
			{
				Assert::AreEqual(rt[v][c], rt3[m++]);
			}
			m++;
		}

		a = a + time + 1;
		time = 0;
		free(rt);
		memset(section, 0, sizeof(section));
	}
}