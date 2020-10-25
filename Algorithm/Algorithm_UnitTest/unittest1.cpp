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
			// TODO:  在此输入测试代码
			char *filename = "..\\Algorithm\\config\\01_ContainsNearbyDuplicate.ini";
			char *numsname = "Array";//数组名
			char *keyname = "Key";
			char *key1 = "Output";
			char section1[MAX_LINE] = { '\0' };//section1--该文件下所有节名保存数组
			int a = 0;
			GetPrivateProfileSectionNamesA(section1, MAX_LINE, filename);
			char section[MAX_LINE] = { '\0' };//保存单个节名数组
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
				int len = strlen(section);//判断节名是否读取到
				//Assert::IsNotNull(section);

				bool r = Key_Juage(section, numsname, filename, keyname);//判断函数输出是true还是false
				//Assert::IsTrue(r);

				int t = Write_Juage(r, section, key1, filename);//判断结果写入是否成功
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

			char section1[MAX_LINE] = { '\0' };//section1--该文件下所有节名保存数组
			int a = 0;
			GetPrivateProfileSectionNamesA(section1, MAX_LINE, filename);
			char section[MAX_LINE] = { '\0' };//保存单个节名数组
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
				Assert::IsNotNull(section);//检测section

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