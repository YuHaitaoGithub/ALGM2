#include "..\Statement.h"
#include "..\stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define MAX_LINE 200

struct ListNode
{
	int val;
	struct ListNode *next;
}*Head = NULL, *End = NULL,*Temp = NULL;

void CreatList(int *buff,int t)
{
	for (int i = 0; i < t; i++)
	{
		if (Head == NULL)
		{
			Temp = (ListNode*)malloc(sizeof(ListNode));
			if (Temp == NULL)
				Logger::WriteMessage("�����ڴ�ʧ��");
			Temp->val = buff[i];
			Temp->next = NULL;
			Head = Temp;
			End = Temp;
			End->next = NULL;
		}
		else
		{
			Temp = (ListNode*)malloc(sizeof(ListNode));
			if (Temp == NULL)
				Logger::WriteMessage("�����ڴ�ʧ��");
			Temp->val = buff[i];
			Temp->next = NULL;
			End->next = Temp;
			End = Temp;
			End->next = NULL;
		}
	}
}

void FreeList()
{

}

void Algm24_Test()
{
	char *filename = "..\\Algorithm\\Config\\24_LengthOfLongestSubstring.ini";
	char *input = "Input";
	char *output = "Output";

	char section1[MAX_LINE] = { '\0' };//section1--���ļ������н�����������
	int a = 0;
	GetPrivateProfileSectionNamesA(section1, MAX_LINE, filename);
	char section[MAX_LINE] = { '\0' };//���浥����������
	int time = 0;
	while ((section1[a] != '\0') || (section1[a + 1] != '\0'))
	{
		for (int k = a; section1[k] != '\0'; k++)
			section[time++] = section1[k];

		char buf[200] = {};
		int buff[200] = {};
		GetPrivateProfileStringA(section, input, NULL, buf, 200, filename);
		int t = 1;
		buff[0] = atoi(&buf[0]);
		for (int i = 1; buf[i] != '\0'; i++)
			if (buf[i] == ',')
				buff[t++] = atoi(&buf[++i]);

		CreatList(buff,t);

		int tag = GetPrivateProfileIntA(section, outnum, -1, filename);

		Assert::AreEqual(ret, tag);

		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}
}