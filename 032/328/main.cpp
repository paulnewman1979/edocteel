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
    ListNode* oddEvenList(ListNode* head) {
        if (NULL == head) {
            return NULL;
        } else if (NULL == head->next) {
            return head;
        }

        ListNode* evenHead = head->next;
        ListNode* evenTail = head->next;
        ListNode* oddHead = head;
        ListNode* oddTail = head;
        head = head->next->next;
        evenTail->next = NULL;
        oddTail->next = NULL;

        int count = 0;
        while (NULL != head) {
            if (count == 0) {
                oddTail->next = head;
                oddTail = head;
                head = head->next;
                oddTail->next = NULL;
            } else {
                evenTail->next = head;
                evenTail = head;
                head = head->next;
                evenTail->next = NULL;
            }
            count = 1 - count;
        }
        oddTail->next = evenHead;

        return oddHead;
    }
};

int main(int argc, char* argv[])
{
    int value;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* newNode = NULL;
    cin >> value;
    while (value != -999999) {
        newNode = new ListNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        cin >> value;
    }

    Solution solution;
    ListNode* newList = solution.oddEvenList(head);
    while (newList != NULL) {
        cout << newList->val << endl;
        newNode = newList;
        newList = newList->next;
        delete newNode;
    }

    return 0;
}
