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

        ListNode *end = head;
        ListNode *tail = NULL;
        ListNode *newHead = head;
        ListNode *cur;

        while (NULL != end) {
            end = end->next;
            if (NULL != end) {
                end = end->next;

                cur = newHead->next;
                newHead->next = tail;
                tail = newHead;
                newHead = cur;
            } else {
                newHead = newHead->next;
            }
        }

        end = newHead;
        cur = tail;
        while (NULL != end) {
            if (end->val != cur->val) return false;
            end = end->next;
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
