#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

/**
Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        int countB = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA != NULL) {
            ++ countA;
            curA = curA->next;
        }
        while (curB != NULL) {
            ++ countB;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (countA > countB) {
            while (countA > countB) {
                curA = curA->next;
                -- countA;
            }
        } else {
            while (countB > countA) {
                curB = curB->next;
                -- countB;
            }
        }
        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }
        
        return curA;
    }
};
   
int main(int argc, char* argv[])
{
	ListNode *headA = NULL;
	ListNode *headB = NULL;
    Solution solution;
	solution.getIntersectionNode(headA, headB);

    return 0;
}
