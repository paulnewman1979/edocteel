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
    bool isPalindrome(ListNode* head) {
        if ((NULL == head) || (NULL == head->next)) return true;

        ListNode *center = head;
        ListNode *cur = head;
        while (NULL != cur) {
            cur = cur->next;
            if (NULL != cur) {
                cur = cur->next;
            }
            if (NULL != cur) {
                center = center->next;
            }
        }

        ListNode *tail = NULL;
        cur = center->next;
        center->next = NULL;

        while (cur != NULL) {
            center = cur->next;
            cur->next = tail;
            tail = cur;
            cur = center;
        }
        center = tail;
        cur = head;

        while (NULL != center) {
            if (center->val != cur->val) {
                return false;
            }
            center = center->next;
            cur = cur->next;
        }

        return true;
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
	int n;
	vector<int> nums;

	cin >> n;
	while (n != -999999) {
		nums.push_back(n);
		cin >> n;
	}

    ListNode* root = load(nums);
		
    Solution solution;
	cout << (solution.isPalindrome(root) ? "true" : "false") << endl;

    return 0;
}
