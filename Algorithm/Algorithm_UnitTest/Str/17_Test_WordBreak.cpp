#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 200

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void Algm17_Test()
{
	char *filename = "..\\Algorithm\\Config\\17_WordBreak.ini";
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

		char In_buf1[500] = {};
		GetPrivateProfileStringA(section,input1 ,NULL,In_buf1, 500, filename);

		char In_buf2[500] = {};
		char *wordDict[100] = {};
		int wordSize = 0;
		int j = 0;
		int n = 0;
		GetPrivateProfileStringA(section, input2, NULL, In_buf2, 500, filename);
		for (int i = 0; In_buf2[i] != '\0';i = j)
		{
			wordDict[wordSize] = (char*)calloc(200, 1);
			n = 0;
			while (In_buf2[j] != ','&&In_buf2[j] != '\0')
			{
				wordDict[wordSize][n] = In_buf2[j];
				j++; n++;
			}
			wordSize++; j++;
		}
		int ret = WordBreak(In_buf1, wordDict, wordSize);

		char out[10] = {};
		int tag = 0;
		GetPrivateProfileStringA(section, output, NULL, out,10, filename);
		if(out[0] == 't')tag = 1;

		Assert::AreEqual(ret, tag);

		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}
}