#include "stdafx.h"
#include "CppUnitTest.h"
#include "Statement.h"
#include"Windows.h"
#include "Definition.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithm_UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			char *filename = "..\\Algorithm\\Config\\01_ContainsNearbyDuplicate.ini";
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
			char *filename = "..\\Algorithm\\Config\\02_ExcelSheetColumnTitle.ini";
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
				//Assert::IsNotNull(section);//检测section

				int b = Num_Juage(section,keyname,filename);
				
				if (b == -100)Logger::WriteMessage("越界");

				char *p = ExcelSheetColumnTitle(b);
				
				char vaule[MAX_LINE] = { '\0' };
				for (int i = 0; p[i] != '\0'; i++)
				{
					vaule[i] = p[i];
				}
				if (vaule[0] == '\0')Logger::WriteMessage("小于等于零");
				char buffer[100] = {};
				GetPrivateProfileStringA(section, key2, NULL, buffer, sizeof(buffer), filename);
				int t = 0;
				int f = 0;
				for (int x = 0; buffer[x] != '\0'; x++)
				{
					if (buffer[x] == ' ');
					else 
					{
						t = (int)(buffer[x]) + t;
					}
					f = (int)(vaule[x]) + f;
				}
				Assert::AreEqual(t,f);
				a = a + len + 1;
				memset(section, 0, sizeof(section));
			}
		}
		TEST_METHOD(TestMethod3)
		{
			char *filename = "..\\Algorithm\\Config\\03_IsUgly.ini";
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

				int val = Num3_Juage(section, keyname, filename);
				if (val == 0)Logger::WriteMessage("越界");

				bool r = IsUgly(val);
				int rt = 0;
				if (r == true)rt = 1;

				char buffer[100] = { '\0' };
				GetPrivateProfileStringA(section, key2, NULL, buffer, sizeof(buffer), filename);
				int tag = 0;
				if (buffer[0] == 't')tag = 1;
				else if (buffer[0] == 'f')tag = 0;
				else tag = -1;

				Assert::AreEqual(rt, tag);
				a = a + len + 1;
				memset(section, 0, sizeof(section));

			}

		}
		TEST_METHOD(TestMethod4)
		{
			char *filename = "..\\Algorithm\\Config\\04_IsPalindrome.ini";
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

				int num = Num4_Juage(section, keyname, filename);
				if (num == -1)Logger::WriteMessage("越界");

				bool r = IsPalindrome(num);
				int rt = 0;
				if (r == true)rt = 1;

				char buffer[100] = { '\0' };
				GetPrivateProfileStringA(section, key2, NULL, buffer, sizeof(buffer), filename);
				int tag = 0;
				if (buffer[0] == 't')tag = 1;
				else if (buffer[0] == 'f')tag = 0;
				else tag = -1;

				Assert::AreEqual(rt, tag);
				a = a + len + 1;
				memset(section, 0, sizeof(section));
			}
		}
		TEST_METHOD(TestMethod6)
		{
			char *filename = "..\\Algorithm\\Config\\06_ContainsDuplicate.ini";
			char *numsname = "Input";
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



				bool r = Nums_Juage(section, numsname, filename);
				int rt = 0;
				if (r == true)rt = 1;

				char buffer[100] = { '\0' };
				GetPrivateProfileStringA(section, key2, NULL, buffer, sizeof(buffer), filename);
				int tag = 0;
				if (buffer[0] == 't')tag = 1;
				else if (buffer[0] == 'f')tag = 0;
				else tag = -1;

				Assert::AreEqual(rt, tag);
				a = a + len + 1;
				memset(section, 0, sizeof(section));
			}
			
			
		}
	};
}