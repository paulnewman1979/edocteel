#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head) {
            return NULL;
        } else if (NULL == head->next) {
            return head;
        }

        ListNode* newHead = head->next;
        ListNode* newTail = head;
        ListNode* p = head->next->next;
        ListNode* t;

        newHead->next = newTail;
        newTail->next = NULL;

        while ( (NULL != p)
            && (NULL != p->next) ) {
            newTail->next = p->next;
            newTail = p->next;
            t = newTail->next;

            newTail->next = p;
            newTail = p;
            newTail->next = NULL;

            p = t;
        }

        if (NULL != p) {
            newTail->next = p;
        }

        return newHead;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums;
    int num;
    cin >> num;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while (num != -999999)
    {
        ListNode* newNode = new ListNode(num);
        if (NULL == head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> num;
    }

    Solution solution;
    ListNode* newHead = solutio.swapPairs(head);
    ListNode* t = newHead;
    while (t != NULL) {
        cout << t->val << endl;
        t = t->next;
    }
}
