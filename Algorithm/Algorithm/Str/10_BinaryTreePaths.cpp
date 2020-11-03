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
	index += sprintf(temp + index, "%d->", root->val);      //将结点值与箭头存入字符数组，并移动下标
	//判断叶子节点，并赋值给结果数组
	if (!root->left && !root->right)
	{
		res[*returnSize] = (char*)calloc(index - 1, sizeof(char));  //因最后一个箭头不需要，所以index-1空间就够了
		if (res[*returnSize] == NULL)
			return;
		temp[index - 2] = '\0';       //最后一位退两格，去掉箭头
		strcpy(res[*returnSize], temp);
		(*returnSize)++;
		return;
	}
	if (root->left)
	{                 //递归遍历左子树
		Dfs(root->left, returnSize, temp, index, res);
	}
	if (root->right)
	{                //递归遍历右子树
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


