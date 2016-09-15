#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (NULL == head) {
            return NULL;
        }
        
        ListNode* s = head;
        ListNode* tail;
        int count = 0;
        while (NULL != s) {
            ++ count;
            tail = s;
            s = s->next;
        }
        
        int steps = count - k % count;
        count = 1;
        s = head;
        while (count < steps) {
            s = s->next;
            ++ count;
        }
        
        tail->next = head;
        head = s->next;
        s->next = NULL;
        
        return head;
    }
};

int main(int argc, char* argv[])
{
	ListNode* head = NULL;
	ListNode* tail = NULL;
	ListNode* newNode;

	int n;
	int k;
	cin >> k;
	cin >> n;
	while (n != -999999) {
		newNode = new ListNode(n);
		if (NULL == tail) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		cin >> n;
	}

    Solution solution;
	head = solution.rotateRight(head, k);
	tail = head;
	while (tail != NULL) {
		cout << tail->val << endl;
		tail = tail->next;
	}

    return 0;
}
