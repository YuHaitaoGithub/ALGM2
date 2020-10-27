#include "stdafx.h"
#include "CppUnitTest.h"
#include "Statement.h"
#include"Windows.h"
#define MAX_LINE 1024

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithm_UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
		
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char *filename = "..\\Algorithm\\Config\\01_ContainsNearbyDuplicate.ini";
			char *numsname = "Array";//数组键名
			char *keyname = "Key";//输入键名
			char *key1 = "Output";//输出键名
			char section1[MAX_LINE] = { '\0' };//section1--保存该文件下所有节名保存数组
			int a = 0;
			GetPrivateProfileSectionNamesA(section1, MAX_LINE, filename);
			char section[MAX_LINE] = { '\0' };//保存单个节名数组
			int time = 0;
			while ((section1[a] != '\0') || (section1[a + 1] != '\0'))
			{
				for (int k = a; section1[k] != '\0'; k++)
					section[time++] = section1[k];
				Assert::IsNotNull(section);//判断是否节名数组为空

				/*判断函数输出是true还是false*/
				bool r = Read_Input(section, numsname, filename, keyname);
				int ret1 = r;
				int ret2 = Read_Output(section, key1, filename);//读取案例的输出
				Assert::AreEqual(ret1, ret2);

				a = a + time + 1;
				time = 0;
				memset(section, 0, sizeof(section));//初始化数组
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
		TEST_METHOD(TestMethod8)
		{
			
			char *filename = "..\\Algorithm\\Config\\08_HammingWeight.ini";
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
				unsigned int ret = Num8_Juage(section, keyname, filename);

				int f_ret = HammingWeight(ret);

				int k = GetPrivateProfileIntA(section, key2, -1, filename);
				Assert::AreEqual(f_ret, k);
				a = a + len + 1;
				memset(section, 0, sizeof(section));
			}
		}
	};
}