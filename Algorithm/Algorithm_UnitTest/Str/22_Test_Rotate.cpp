#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 200

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Algm22_Test()
{
	char *filename = "..\\Algorithm\\Config\\22_Rotate.ini";
	char *num = "Input";
	char *k = "k";
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

		char buf[500] = {};
		vector<int>In_buf;
		int h = 0;
		GetPrivateProfileStringA(section, num, NULL, buf, 500, filename);
		In_buf.push_back(atoi(&buf[0]));
		for (int i = 0; buf[i] != '\0';i++)
			if (buf[i] == ',')
				In_buf.push_back(atoi(&buf[++i]));
		int in_k = GetPrivateProfileIntA(section, k,-1, filename);

		Rotate(In_buf, in_k);

		h = 0;
		char buff[500] = {};
		int Out_buff[500] = {};
		GetPrivateProfileStringA(section, outnum, NULL, buff, 500, filename);
		Out_buff[h++] = atoi(&buff[0]);
		for (int i = 0; buff[i] != '\0'; i++)
			if (buff[i] == ',')
				Out_buff[h++] = atoi(&buff[++i]);

		for (int i = 0; i < h; i++)
		{
			Assert::AreEqual(In_buf[i], Out_buff[i]);
		}

		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}
}