#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 200

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Algm20_Test()
{
	char *filename = "..\\Algorithm\\Config\\20_MoveZeroes.ini";
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
		vector<int>In_buf;
		int l = 0;
		GetPrivateProfileStringA(section, num, NULL, buf, 200, filename);
		In_buf.push_back(atoi(&buf[0]));
		for (int i = 1; buf[i] != '\0';i++)
			if (buf[i] == ',')
				In_buf.push_back(atoi(&buf[++i]));
		MoveZeroes(In_buf);

		char buff[100] = {};
		l = 0;
		vector<int>Out_buf;
		GetPrivateProfileStringA(section, outnum, NULL, buff, 200, filename);
		Out_buf.push_back(atoi(&buff[0]));
		for (int i = 0; buff[i] != '\0'; i++)
			if (buff[i] == ',')
				Out_buf.push_back(atoi(&buff[++i]));

		for (int i = 0; i < In_buf.size(); i++)
		{
			Assert::AreEqual(In_buf[i], Out_buf[i]);
		}

		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}
}