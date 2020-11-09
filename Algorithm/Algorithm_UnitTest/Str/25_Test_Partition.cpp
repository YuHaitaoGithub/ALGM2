#include "..\Statement.h"
#include "..\stdafx.h"
#include "string.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define MAX_LINE 200

struct ListNode
{
	int val;
	struct ListNode *next;
}*Head = NULL, *End = NULL, *Temp = NULL, *T = NULL;



void CreatList(int *buff, int t)
{
	/*if (buff[0] == -1)return;*/
	for (int i = 0; i < t; i++)
	{
		if (Head == NULL)
		{
			Temp = (ListNode*)malloc(sizeof(ListNode));
			if (Temp == NULL)
				Logger::WriteMessage("申请内存失败");
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
				Logger::WriteMessage("申请内存失败");
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
	if (Head->next == NULL)
	{

		free(Head);
		Head = NULL;
		End = NULL;
	}
	else if (Head->next == End)
	{

		free(Head);
		free(End);
		Head = NULL;
		End = NULL;
	}
	else
	{
		struct ListNode *F = Head;
		while (Head->next != NULL)
		{
			Head = Head->next;
			free(F);
			F = Head;
		}
		free(F);
		Head = NULL;
		End = NULL;
		F = NULL;
	}
}

void Algm25_Test()
{
	char *filename = "..\\Algorithm\\Config\\25_Partition.ini";
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

		char buf[200] = {};
		int buff[200] = {};
		GetPrivateProfileStringA(section, input1, NULL, buf, 200, filename);
		int t = 1;
		if (buf != NULL)
		{
			buff[0] = atoi(&buf[0]);
			for (int i = 1; buf[i] != '\0'; i++)
				if (buf[i] == ',')
					buff[t++] = atoi(&buf[++i]);
			CreatList(buff, t);
		}
		else Head = NULL;
		

		char x1[20] = {};
		GetPrivateProfileStringA(section, input2, NULL, x1, 20, filename);
		if (x1 != NULL)
		{
			int x = atoi(&x1[0]);
			T = Partition(Head, x);
		}
		else T = Head;

		char out[200] = {};
		int retout[200] = {};
		GetPrivateProfileStringA(section, output, NULL,out, 200, filename);
		
		int k = 1;
		retout[0] = atoi(&out[0]);
		for (int i = 1; out[i] != '\0'; i++)
			if (out[i] == ',')
				retout[k++] = atoi(&out[++i]);
	
		
		int j = 0;
		while (T != NULL)
		{
			Assert::AreEqual(T->val, retout[j++]);
			T = T->next;
		}

		FreeList();
		T = NULL;
		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));
	}
}