#include "..\Statement.h"
#include "..\stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define MAX_LINE 1000

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}BinNode, *BinTree;
BinTree root1;



void CreateBinTree2(BinTree &root1, int* array, int i)
{

	if (array[i] == -11){
		return;
	}
	if (root1 == NULL){
		root1 = (BinNode *)malloc(sizeof(BinNode));
		root1->val = array[i];
		root1->left = NULL;
		root1->right = NULL;
	}
	CreateBinTree2(root1->left, array, 2 * i);
	CreateBinTree2(root1->right, array, 2 * i + 1);
}

void Freetree2(BinTree &root1)
{
	if (root1 != NULL)
	{
		Freetree2(root1->left);
		Freetree2(root1->right);
		root1 = NULL;
		free(root1);	//�������ӽ�㶼Ϊ��ʱ������free,�ͷſռ�
	}
}

void Algm10_Test()
{
	char *filename = "..\\Algorithm\\Config\\10_BinaryTreePaths.ini";
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

		/*��ȡ�����˼�ֵ*/
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
		for (int z = k; z <= (2 * k - 1); z++)//��-1�����
		{
			array_a[z] = -11;
		}

		/*����������*/
		int i = 1;
		CreateBinTree2(root1,array_a, i);

		/*����Ҫ��ĺ���*/
		int h = 0;
		int *returnSize1 = &h;
		*returnSize1 = 0;
		char **rt = BinaryTreePaths(root1, returnSize1);

		/*��ȡ���*/
		char rt2[200] = {};
		char rt3[200] = {};
		GetPrivateProfileStringA(section, output,NULL,rt2,200, filename);
		for (int v = 0; rt2[v] != '\0'; v++)
			if ((rt2[v] != ',') && (rt2[v] != '\"'))rt3[v] = rt2[v];

		for (int v = 0; v < *returnSize1; v++)
		{
			for (int c = 0; rt[v][c] != '\0'; c++)
			{
				Assert::AreEqual(rt[v][c], rt2[v]);
			}
		}
		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));

		free(rt);
		Freetree2(root1);//�ͷŵ�һ�����������ڴ�
	}
}