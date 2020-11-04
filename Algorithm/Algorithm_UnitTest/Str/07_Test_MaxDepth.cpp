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
BinTree Tree;



void CreateBinTree1(BinTree &Tree, int* array, int i)
{

	if (array[i] == -11){
		return;
	}
	if (Tree == NULL){
		Tree = (BinNode *)malloc(sizeof(BinNode));
		if (Tree == NULL)return;
		Tree->val = array[i];
		Tree->left = NULL;
		Tree->right = NULL;
	}
	CreateBinTree1(Tree->left, array, 2 * i);
	CreateBinTree1(Tree->right, array, 2 * i + 1);
}

void Freetree1(BinTree &Tree)
{
	if (Tree != NULL)
	{
		Freetree1(Tree->left);
		Freetree1(Tree->right);
		Tree = NULL;
		free(Tree);	//�������ӽ�㶼Ϊ��ʱ������free,�ͷſռ�
	}
}

void Algm7_Test()
{
	char *filename = "..\\Algorithm\\Config\\07_MaxDepth.ini";
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
		CreateBinTree1(Tree, array_a, i);

		/*����Ҫ��ĺ���*/
		int rt1 = MaxDepth(Tree);

		/*��ȡ���*/
		int rt2 = GetPrivateProfileIntA(section, output, -1, filename);

		Assert::AreEqual(rt1, rt2);
		a = a + time + 1;
		time = 0;
		memset(section, 0, sizeof(section));

		Freetree1(Tree);//�ͷŵ�һ�����������ڴ�
	}
}