#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\10_BinaryTreePaths.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

typedef struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void Dfs(struct TreeNode* root, int* returnSize, char* temp, int index, char** res){
	index += sprintf(temp + index, "%d->", root->val);      //�����ֵ���ͷ�����ַ����飬���ƶ��±�
	//�ж�Ҷ�ӽڵ㣬����ֵ���������
	if (!root->left && !root->right)
	{
		res[*returnSize] = (char*)calloc(index - 1, sizeof(char));  //�����һ����ͷ����Ҫ������index-1�ռ�͹���
		if (res[*returnSize] == NULL)
			return;
		temp[index - 2] = '\0';       //���һλ������ȥ����ͷ
		strcpy(res[*returnSize], temp);
		(*returnSize)++;
		return;
	}
	if (root->left)
	{                 //�ݹ����������
		Dfs(root->left, returnSize, temp, index, res);
	}
	if (root->right)
	{                //�ݹ����������
		Dfs(root->right, returnSize, temp, index, res);
	}
}

char **BinaryTreePaths(struct TreeNode *root, int* returnSize){
	if (!root)
		return NULL;

	char** res = (char**)malloc(sizeof(char*)*100);  
	if (res == NULL)
		return false;
	char* temp = (char*)malloc(sizeof(char) * 1024);  
	if (temp == NULL)
		return false;
	Dfs(root, returnSize, temp, 0, res);
	free(temp);
	return res;
}


