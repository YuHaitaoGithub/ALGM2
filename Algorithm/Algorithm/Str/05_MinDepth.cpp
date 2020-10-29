#include "..\Include\05_MinDepth.h"
#include "stdio.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int MinDepth(struct TreeNode* root)
{
	if (root == NULL){
		return 0;
	}
	int left_d = MinDepth(root->left);
	int right_d = MinDepth(root->right);
	//left_d和right_d有一个为0说明对应的一边没有叶子节点, 
	if (left_d == 0 && right_d != 0) {
		return 1 + right_d;
	}
	if (right_d == 0 && left_d != 0) {
		return 1 + left_d;
	}
	if (left_d == 0 || right_d == 0){
		return left_d + right_d + 1;
	}
	return MIN(left_d, right_d) + 1;
}