#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int size = 0;
        while (cur != NULL) {
            cur = cur->next;
            ++ size;
        }

        if (size < n) {
            return head;
        }
        else if (size == n) {
            return head->next;
        }
        else {
            int i = 1;
            ListNode* cur = head;
            while (i < size - n) {
                cur = cur->next;
                ++ i;
            }
            cur->next = cur->next->next;
            return head;
        }
    }
};

int main(int argc, char* argv[])
{
    int n;
    int value;
    ListNode* head = NULL;
    ListNode* cur = NULL;
    ListNode* newnode = NULL;
    cin >> n;

    cin >> value;
    while (value != -999999) {
        newnode = new ListNode(value);
        if (NULL == head) {
            head = newnode;
            cur = newnode;
        }
        else {
            cur->next = newnode;
        }

        cin >> value;
    }

    Solution solution;
    head = solution.removeNthFromEnd(head, n);
    cur = head;
    while (cur != NULL) {
        cout << cur->val << endl;
        cur = cur->next;
    }
}
