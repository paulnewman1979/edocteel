#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
		if (NULL == head) {
			return;
		}

		ListNode* cur = NULL;
		ListNode* s = NULL;
		ListNode* t = NULL;
		int size = 0;
		cur = head;
		while (NULL != cur) {
			++ size;
			cur = cur->next;
		}

		if (size <= 2) {
			return;
		}

		int halfSize = (size + 1) / 2;
		cur = head;
		while (halfSize > 1) {
			-- halfSize;
			cur = cur->next;
		}

		s = cur->next;
		cur->next = NULL;

		cur = s->next;
		s->next = NULL;
		while (NULL != cur) {
			t = cur->next;
			cur->next = s;
			s = cur;
			cur = t;
		}

		cur = s;

		s = head;
		t = cur;
		ListNode* p = NULL;
		while (t != NULL) {
			p = t->next;
			t->next = s->next;
			s->next = t;

			s = t->next;
			t = p;
		}
    }
};

int main(int argc, char* argv[])
{
	ListNode* head = NULL;
	ListNode* tail = NULL;
	ListNode* cur = NULL;

	int n;
	cin >> n;
	head = new ListNode(n);
	tail = head;

	cin >> n;
	while (n != -999999) {
		cur = new ListNode(n);
		tail->next = cur;
		tail = cur;
		cin >> n;
	}

    Solution solution;
	solution.reorderList(head);
	cur = head;
	while (cur) {
		cout << cur->val << endl;
		cur = cur->next;
	}

    return 0;
}
