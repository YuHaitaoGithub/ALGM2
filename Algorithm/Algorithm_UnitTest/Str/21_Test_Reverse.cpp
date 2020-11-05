#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 200

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Algm21_Test()
{
	char *filename = "..\\Algorithm\\Config\\21_Reverse.ini";
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

		char buf[20] = {};
		GetPrivateProfileStringA(section, num, NULL, buf, 20, filename);
		int In_buf = atoi(&buf[0]);
		int ret = Reverse(In_buf);

		char buff[20] = {};
		GetPrivateProfileStringA(section, outnum, NULL, buff, 20, filename);
		int tag = atoi(&buff[0]);

		Assert::AreEqual(ret, tag);

		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}
}