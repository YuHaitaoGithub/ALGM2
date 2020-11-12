#include "..\Include\05_MinDepth.h"
#include "stdio.h"
#include <queue>

using namespace std;

//#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//后序
//int MinDepth(struct TreeNode* root)
//{
//	if (root == NULL){
//		return 0;
//	}
//	int left_d = MinDepth(root->left);
//	int right_d = MinDepth(root->right);
//	//left_d和right_d有一个为0说明对应的一边没有叶子节点, 
//	if (left_d == 0 && right_d != 0) {
//		return 1 + right_d;
//	}
//	if (right_d == 0 && left_d != 0) {
//		return 1 + left_d;
//	}
//	if (left_d == 0 || right_d == 0){
//		return left_d + right_d + 1;
//	}
//	return MIN(left_d, right_d) + 1;
//}

//层序
int MinDepth(struct TreeNode* root)
{
	if (NULL == root)
		return 0;

	queue<pair<TreeNode*, int>>my_queue;
	TreeNode* p = NULL;
	int min = 1;
	my_queue.push({ root, 1 });
	while (!my_queue.empty())
	{
		min = my_queue.front().second;
		p = my_queue.front().first;
		my_queue.pop();

		if (p->left == NULL&&p->right == NULL)
			return min;
		if (p->left != NULL)
			my_queue.push({ p->left, min + 1 });
		if (p->right != NULL)
			my_queue.push({ p->right, min + 1 });
	}
}