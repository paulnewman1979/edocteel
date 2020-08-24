#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

typedef BaseListNode<int> ListNode;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ret;
        return ret;
    }
};

ListNode* load(vector<int> &nums)
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    for (size_t i = 0; i < nums.size(); i++) {
        if (NULL == head) {
            head = new ListNode(nums[i]);
            tail = head;
        } else {
            tail->next = new ListNode(nums[i]);
            tail = tail->next;
        }
    }
    return head;
}

int main(int argc, char* argv[])
{
    // input
    int k;
    ListNode* root = NULL;
    Input(k);
    Input(root);

    // solution
    Solution solution;
    vector<ListNode*> listVec = solution.splitListToParts(root, k);

    // output
    Output(listVec);

    return 0;
}
