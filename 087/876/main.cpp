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
	vector<int> values;

    int n;
    int value;
	cin >> n;
	while (--n >= 0) {
        cin >> value;
		values.push_back(value);
	}

    ListNode* root = load(values);
		
    Solution solution;
    ListNode* midNode = solution.middleNode(root);
	cout << midNode->val << endl;

    return 0;
}
