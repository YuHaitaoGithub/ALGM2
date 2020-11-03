#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 500
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Algm15_Test()
{
	char *filename = "..\\Algorithm\\Config\\15_WordPattern.ini";
	char *pattern = "Pattern";
	char *str = "Str";
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

		char buf[200] = {};
		char buffer[MAX_LINE] = {};
		GetPrivateProfileStringA(section, pattern, NULL, buf, 200, filename);
		GetPrivateProfileStringA(section,str, NULL, buffer, MAX_LINE, filename);

		int f_ret = WordPattern(buf, buffer);

		char out[10] = {};
		GetPrivateProfileStringA(section, output, NULL, out, 10, filename);
		int tag = 0;
		if (out[0] == 't')tag = 1;
		
		Assert::AreEqual(f_ret, tag);
		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}


}