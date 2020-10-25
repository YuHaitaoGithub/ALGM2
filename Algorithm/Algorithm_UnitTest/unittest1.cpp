#include "stdafx.h"
#include "CppUnitTest.h"
#include "Statement.h"
#include"Windows.h"
#include "..\Algorithm\Include\02_ExcelSheetColumnTitle.h"

#define MAX_LINE 1024

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithm_UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  �ڴ�������Դ���
			char *filename = "..\\Algorithm\\config\\01_ContainsNearbyDuplicate.ini";
			char *numsname = "Array";//������
			char *keyname = "Key";
			char *key1 = "Output";
			char section1[MAX_LINE] = { '\0' };//section1--���ļ������н�����������
			int a = 0;
			GetPrivateProfileSectionNamesA(section1, MAX_LINE, filename);
			char section[MAX_LINE] = { '\0' };//���浥����������
			int time = 0;
			while ((section1[a] != '\0') || (section1[a + 1] != '\0'))
			{
				for (int k = a; section1[k] != '\0'; k++)
				{
					if (section1[k] != ' ')
					{
						section[time] = section1[k];
						time++;
					}
				}
				time = 0;
				int len = strlen(section);//�жϽ����Ƿ��ȡ��
				//Assert::IsNotNull(section);

				bool r = Key_Juage(section, numsname, filename, keyname);//�жϺ��������true����false
				//Assert::IsTrue(r);

				int t = Write_Juage(r, section, key1, filename);//�жϽ��д���Ƿ�ɹ�
				if(t == 1)Assert::AreEqual(t, 1);
				else Assert::AreEqual(t, 0);
				a = a + len + 1;
				memset(section, 0, sizeof(section));
			}
		}
		TEST_METHOD(TestMethod2)
		{
			char *filename = "..\\Algorithm\\config\\02_ExcelSheetColumnTitle.ini";
			char *keyname = "Input";
			char *key2 = "Output";

			char section1[MAX_LINE] = { '\0' };//section1--���ļ������н�����������
			int a = 0;
			GetPrivateProfileSectionNamesA(section1, MAX_LINE, filename);
			char section[MAX_LINE] = { '\0' };//���浥����������
			int time = 0;
			while ((section1[a] != '\0') || (section1[a + 1] != '\0'))
			{
				for (int k = a; section1[k] != '\0'; k++)
				{
					if (section1[k] != ' ')
					{
						section[time] = section1[k];
						time++;
					}
				}
				time = 0;
				int len = strlen(section);
				Assert::IsNotNull(section);//���section

				int b = Num_Juage(section,keyname,filename);
				

				char *p = ExcelSheetColumnTitle(b);
				char vaule[MAX_LINE] = { '\0' };
				for (int i = 0; p[i] != '\0'; i++)
				{
					vaule[i] = p[i];
				}
				char buffer[100] = {};
				GetPrivateProfileStringA(section, key2, NULL, buffer, sizeof(buffer), filename);
				bool t;
				for (int x = 0; buffer[x] != '\0'; x++)
				{
					if (buffer[x] == ' ');
					else if (buffer[x] != vaule[x])t = false;
						
				}
				Assert::IsFalse(t);
				a = a + len + 1;
				memset(section, 0, sizeof(section));
			}
		}

	};
}