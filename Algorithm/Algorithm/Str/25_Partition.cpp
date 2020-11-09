#include "..\Include\25_Partition.h"

using namespace std;


struct ListNode* Partition(struct ListNode* head, int x)
{
	vector<int>max;
	vector<int>min;
	if (head == NULL)return NULL;
	int t = 0;
	int i = 0;
	int j = 0;
	ListNode *Juage = head;
	while (Juage != NULL)
	{
		if (Juage->val >= x)
			max.push_back(Juage->val);
		else
			min.push_back(Juage->val);
		Juage = Juage->next;
	}
	Juage = head;
	while (Juage != NULL)
	{
		if (min.begin() + i < min.end() && min.size())
			Juage->val = *(min.begin() + i);
		else if (max.size())
			Juage->val = *(max.begin() + j);
		i++; j++;
		Juage = Juage->next;
	}
	return head;
}