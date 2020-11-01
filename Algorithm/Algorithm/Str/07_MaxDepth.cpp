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

	if (left_d == 0 && right_d == 0){
		return 1;
	}
	return left_d < right_d ? (right_d + 1) : (left_d + 1);
}