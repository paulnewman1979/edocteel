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

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
		vector<int> nums;
		while (NULL != head) {
			nums.push_back(head->val);
			head = head->next;
		}

		return sortedArrayToBST(nums);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (0 == nums.size()) {
			return NULL;
		}

		return sortedArrayToBST(nums, 0, nums.size());
    }

	TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
		TreeNode* root = NULL;
		switch(end-start) {
		case 1:
			root = new TreeNode(nums[start]);
			return root;
		case 2:
			root = new TreeNode(nums[start+1]);
			root->left = new TreeNode(nums[start]);
			return root;
		case 3:
			root = new TreeNode(nums[start+1]);
			root->left = new TreeNode(nums[start]);
			root->right = new TreeNode(nums[start+2]);
			return root;
		default:
			int median = (start + end) / 2;
			root = new TreeNode(nums[median]);
			root->left = sortedArrayToBST(nums, start, median);
			root->right = sortedArrayToBST(nums, median + 1, end);
			return root;
		}
	}
};

void printNode(TreeNode* root) {
	if (NULL == root) {
		return;
	}

	cout << root->val << endl;
	printNode(root->left);
	printNode(root->right);
}

int main(int argc, char* argv[])
{
	vector<int> nums;
	
	int n;
	cin >> n;
	ListNode* head = NULL;
	ListNode* tail = NULL;
	while (n != -999999) {
		if (NULL == head) {
			head = new ListNode(n);
			tail = head;
		} else {
			tail->next = new ListNode(n);
			tail = tail->next;
		}
		cin >> n;
	}

    Solution solution;
	TreeNode* root = solution.sortedListToBST(head);

	printNode(root);

    return 0;
}
