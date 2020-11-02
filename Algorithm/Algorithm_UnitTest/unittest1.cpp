#include "stdafx.h"
#include "CppUnitTest.h"
#include "Statement.h"

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
						section[time++] = section1[k];
				/*读输入值*/
				int b = Read_Num(section, keyname, filename);
				/*传入函数*/
				char *p = ExcelSheetColumnTitle(b);
				char v[10] = {};
				for (int i = 0; p[i] != '\0'; i++)
				{
					v[i] = p[i];
				}
				/*读输出值*/
				char buffer[100] = {};
				GetPrivateProfileStringA(section, key2, NULL, buffer, sizeof(buffer), filename);
				int t = 0;
				int f = 0;
				for (int x = 0; buffer[x] != '\0'; x++)
				{
					t = (int)(buffer[x]) + t;
					f = (int)(v[x]) + f;
				}
				Assert::AreEqual(t,f);
				a = a + time + 1;
				time = 0;
				memset(section, 0, sizeof(section));
			}
		}
		TEST_METHOD(TestMethod3)
		{
			Algm3_Test();
		}
		TEST_METHOD(TestMethod4)
		{
			Algm4_Test();
		}
		TEST_METHOD(TestMethod5)
		{
			Algm5_Test();
		}
		TEST_METHOD(TestMethod6)
		{
			Algm6_Test();
		}
		TEST_METHOD(TestMethod7)
		{
			Algm7_Test();
		}
		TEST_METHOD(TestMethod8)
		{
			Algm8_Test();
		}
		TEST_METHOD(TestMethod9)
		{
			Algm9_Test();
		}
		TEST_METHOD(TestMethod10)
		{
			Algm10_Test();
		}
		TEST_METHOD(TestMethod11)
		{
			Algm11_Test();
		}
		TEST_METHOD(TestMethod12)
		{
			Algm12_Test();
		}
		TEST_METHOD(TestMethod13)
		{
			Algm13_Test();
		}
	};
}