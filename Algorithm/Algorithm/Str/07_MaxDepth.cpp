#include "..\Include\07_MaxDepth.h"
#include "stdio.h"

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int MaxDepth(struct TreeNode* root)
{
	if (root == NULL){
		return 0;
	}
	int left_d = MaxDepth(root->left);
	int right_d = MaxDepth(root->right);
	//left_d��right_d��һ��Ϊ0˵����Ӧ��һ��û��Ҷ�ӽڵ�, 
	if (left_d == 0 && right_d != 0) {
		return 1 + right_d;
	}
	if (right_d == 0 && left_d != 0) {
		return 1 + left_d;
	}
	if (left_d == 0 || right_d == 0){
		return left_d + right_d + 1;
	}
	return left_d < right_d ? (right_d + 1) : (left_d + 1);
}