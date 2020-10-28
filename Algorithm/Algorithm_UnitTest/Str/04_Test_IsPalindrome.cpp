#include "..\Statement.h"
#include "..\stdafx.h"

#define MAX_LINE 1024

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Algm4_Test()
{
	char *filename = "..\\Algorithm\\Config\\04_IsPalindrome.ini";
	char *keyname = "Input";
	char *key2 = "Output";

	
	char section1[MAX_LINE] = { '\0' };//section1--���ļ������н�����������
	int a = 0;
	GetPrivateProfileSectionNamesA(section1, MAX_LINE, filename);
	char section[MAX_LINE] = { '\0' };//���浥����������
	int time = 0;
	while ((section1[a] != '\0') || (section1[a + 1] != '\0'))
	{
		/*����������*/
		for (int k = a; section1[k] != '\0'; k++)
			section[time++] = section1[k];

		/*��INPUT*/
		char key[20] = {};
		GetPrivateProfileStringA(section, keyname, NULL, key, 20, filename);
		int x = atoll(&key[0]);
	
		bool r = IsPalindrome(x);

		/*��OUTPUT*/
		char buffer[100] = { '\0' };
		GetPrivateProfileStringA(section, key2, NULL, buffer, sizeof(buffer), filename);
		int tag = 0;
		if (buffer[0] == 't')tag = 1;

		Assert::AreEqual((int)r, tag);
		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}
}
