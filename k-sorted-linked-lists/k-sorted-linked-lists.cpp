#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* SortedMerge(ListNode* a, ListNode* b) {
	ListNode* result = NULL;
	if (a == nullptr) 
		return b;
	else if (b == nullptr)
		return a;
	
	if (a->val <= b->val) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return result;
}

ListNode* mergeLists(vector<ListNode*>& lists, int n) {
	while (n > 0) {
		int i = 0; j = n;
		while (i < j) {
			lists[i] = SortedMerge(lists[i], lists[j]);
			i++, j--;
			if (i >= j) {
				n = j;
			}
		}
	}
	return lists[0];
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	return mergeLists(lists, lists.size());
}

int main()
{
	return 0;
}
