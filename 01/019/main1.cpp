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
        if (n <= 0) {
            return head;
        }
        else if (NULL == head) {
            return head;
        }

        ListNode* cur = head;
        int i = 1;
        while ((cur != NULL)
                && (i <= n)) {
            cur = cur->next;
            ++ i;
        }

        if (cur == NULL) {
            if (i == n + 1) {
                return head->next;
            }
            return head;
        }
        else {
            ListNode* ncur_pre = head;
            while (cur->next != NULL) {
                ncur_pre = ncur_pre->next;
                cur = cur->next;
            }

            ncur_pre->next = ncur_pre->next->next;
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
