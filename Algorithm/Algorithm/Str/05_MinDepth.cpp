#include "..\Include\05_MinDepth.h"
#include "stdio.h"
#include <queue>

using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//∫Û–Ú
int MinDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	int lift = MinDepth(root->left);
	int right = MinDepth(root->right);
	if (lift == 0 && right != 0)
		return 1 + right;
	if (lift != 0 && right == 0)
		return 1 + lift;
	if (lift == 0 && right == 0)
		return 1;
	return MIN(lift, right) + 1;
}

//≤„–Ú
//int MinDepth(struct TreeNode* root)
//{
//	if (NULL == root)
//		return 0;
//
//	queue<pair<TreeNode*, int>>my_queue;
//	int min = 1;
//	my_queue.push({ root, 1 });
//	while (!my_queue.empty())
//	{
//		min = my_queue.front().second;
//		root = my_queue.front().first;
//		my_queue.pop();
//
//		if (root->left == NULL&&root->right == NULL)
//			return min;
//		if (root->left != NULL)
//			my_queue.push({ root->left, min + 1 });
//		if (root->right != NULL)
//			my_queue.push({ root->right, min + 1 });
//	}
//	return min;
//}