#pragma once
#include <vector>
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* Partition(struct ListNode* head, int x);