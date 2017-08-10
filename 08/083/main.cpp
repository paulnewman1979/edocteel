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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* cur = head;
        while (cur->next != NULL) {
            if (cur->next->val == cur->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        
        return head;
    }
};

int main(int argc, char* argv[])
{
	ListNode* head = NULL;
	ListNode* tail;

	int n;
	cin >> n;
	while (n != -999999) {
		if (NULL == head) {
			head = new ListNode(n);
			tail = head;
		} else {
			tail->next = new ListNode(n);
			tail = tail->next;
		}
		cin >> n;
	}

    Solution solution;
	head = solution.deleteDuplicates(head);
	tail = head;
	while (tail != NULL) {
		cout << tail->val << endl;
		tail = tail->next;
	}

    return 0;
}
