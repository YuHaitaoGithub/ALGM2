#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\05_MinDepth.h"
#include "Windows.h"
#include "stdio.h"
//#include "malloc.h"
//
//
//
//typedef struct TreeNode
//{
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//}BinNode, *BinTree;
//BinTree binTree;
////先序建立
//
//void createBinTree(BinTree &binTree, int* a, int i)
//{
//
//	if (a[i] == -11){
//		return;
//	}
//	if (binTree == NULL){
//		binTree = (BinNode *)malloc(sizeof(BinNode));
//		binTree->val = a[i];
//		binTree->left = NULL;
//		binTree->right = NULL;
//	}
//	createBinTree(binTree->left,a, 2 * i);
//	createBinTree(binTree->right, a, 2 * i + 1);
//}


void main()
{
////	Algm4_Test();
//	int a[120] = { 0 };
//	char *filename = ".\\Config\\05_MinDepth.ini";
//	char *section = "2";
//	char *input = "Input";
//	char b[100] = {};
//	GetPrivateProfileStringA(section, input, NULL, b, 100, filename);
//	int j = 0;
//	int k = 1;
//	for (j; b[j] != '\0'; j++)
//	{
//		if (b[0] == 'n'){
//			a[k++] = -11; break;
//		}
//		if (!j)
//		{
//			a[k++] = atoi(&b[0]); continue;
//		}
//		if (b[j] == ',')
//		{
//			if (b[j+1] == 'n')
//			{
//				a[k++] = -11;
//				j = j + 3;
//
//			}
//			else a[k++] = atoi(&b[++j]);
//		}
//			
//
//	}
//	for (int z = k; z <= (2 * k - 1); z++)
//	{
//		a[z] = -11;
//	}
//	int i = 1;
//	createBinTree(binTree, a, i);
//	printf("二叉树构建完成！\n先序遍历%d\n", MinDepth(binTree));

}