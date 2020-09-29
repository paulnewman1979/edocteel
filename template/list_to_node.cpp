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
    ListNode* middleNode(ListNode* head) {
        if (NULL == head) return NULL;

        int count = 0;
        ListNode* cur = head;
        while (NULL != cur) {
            ++count;
            cur = cur->next;
        }
        if (count % 2 == 0) {
            count = count / 2;
        } else {
            count = (count - 1) / 2;
        }

        cur = head;
        while (count > 0) {
            cur = cur->next;
            --count;
        }

        return cur;
    }
};

int main(int argc, char* argv[])
{
    // input
    ListNode* head = NULL;
    Input(head);

    // process
    Solution solution;
    ListNode* midNode = solution.middleNode(head);

    // output
	Output(midNode->val);

    return 0;
}
