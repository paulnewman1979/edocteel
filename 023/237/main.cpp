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
    void deleteNode(ListNode* node) {
        if (NULL != node) {
            if (NULL != node->next) {
                node->val = node->next->val;
                node->next = node->next->next;
            }
        }
    }
};

ListNode* load(const vector<int> &nums, int nodeValue, ListNode*& node)
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    for (size_t i = 0; i < nums.size(); i++) {
        if (NULL == head) {
            head = new ListNode(nums[i]);
            tail = head;
            if (nums[i] == nodeValue) {
                node = tail;
            }
        } else {
            tail->next = new ListNode(nums[i]);
            tail = tail->next;
            if (nums[i] == nodeValue) {
                node = tail;
            }
        }
    }
    return head;
}

int main(int argc, char* argv[])
{
    int n;
    vector<int> nums;

    int nodeValue;
    cin >> nodeValue;

    cin >> n;
    while (n != -999999) {
        nums.push_back(n);
        cin >> n;
    }

    ListNode *p = NULL;
    ListNode *root = load(nums, nodeValue, p);
    (void)root;
        
    Solution solution;
    solution.deleteNode(p);

    return 0;
}
