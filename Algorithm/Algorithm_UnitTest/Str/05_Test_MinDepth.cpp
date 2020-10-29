#include "..\Statement.h"
#include "..\stdafx.h"
#include "malloc.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define MAX_LINE 1000

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}BinNode, *BinTree;
BinTree binTree;


void createBinTree(BinTree &binTree, int* array, int i)
{

	if (array[i] == -11){
		return;
	}
	if (binTree == NULL){
		binTree = (BinNode *)malloc(sizeof(BinNode));
		binTree->val = array[i];
		binTree->left = NULL;
		binTree->right = NULL;
	}
	createBinTree(binTree->left, array, 2 * i);
	createBinTree(binTree->right, array, 2 * i + 1);
}

void Freetree(BinTree &binTree)
{
	if (binTree != NULL)
	{
		Freetree(binTree->left);
		Freetree(binTree->right);
		binTree = NULL;
		free(binTree);	//当左右子结点都为空时，调用free,释放空间
	}
}

void Algm5_Test()
{
	char *filename = "..\\Algorithm\\Config\\05_MinDepth.ini";
	char *input = "Input";
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

		/*读取并过滤键值*/
		int array_a[200] = { 0 };
		char array_b[150] = {};
		GetPrivateProfileStringA(section, input, NULL, array_b, 100, filename);
		int j = 0;
		int k = 1;
		for (j; array_b[j] != '\0'; j++)
		{
			if (array_b[0] == 'n'){
				array_a[k++] = -11; break;
			}
			if (!j)
			{
				array_a[k++] = atoi(&array_b[0]); continue;
			}
			if (array_b[j] == ',')
			{
				if (array_b[j + 1] == 'n')
				{
					array_a[k++] = -11;
					j = j + 3;

				}
				else array_a[k++] = atoi(&array_b[++j]);
			}
		}
		for (int z = k; z <= (2 * k - 1); z++)//用-1代表空
		{
			array_a[z] = -11;
		}

		/*创建二叉树*/
		int i = 1;
		createBinTree(binTree, array_a, i);

		/*传入要测的函数*/
		int rt1 = MinDepth(binTree);

		/*读取输出*/
		int rt2 = GetPrivateProfileIntA(section, output, -1, filename);

		Assert::AreEqual(rt1, rt2);
		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));

		Freetree(binTree);//释放第一个测试树的内存
	}
}