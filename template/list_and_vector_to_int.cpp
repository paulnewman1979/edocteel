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
    int numComponents(ListNode* head, vector<int>& G) {
        return 0;
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
    int val;
	vector<int> nums;

	cin >> n;
	while (n > 0) {
        cin >> val;
		nums.push_back(val);
        --n;
	}
    ListNode* root = load(nums);

    cin >> n;
    while (n > 0) {
        cin >> val;
        nums.push_back(val);
        --n;
    }
		
    Solution solution;
	cout << solution.numComponents(root, nums) << endl;

    return 0;
}
