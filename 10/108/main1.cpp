#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (0 == nums.size()) {
			return NULL;
		}

		return sortedArrayToBST(nums, 0, nums.size());
    }

	TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
		if (end <= start + 1) {
			TreeNode* root = new TreeNode(nums[start]);
			return root;
		} else if (end == start + 2) {
			TreeNode* root = new TreeNode(nums[start+1]);
			root->left = new TreeNode(nums[start]);
			return root;
		} else {
			int median = (start + end) / 2;
			TreeNode* root = new TreeNode(nums[median]);
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
	while (n != -999999) {
		nums.push_back(n);
		cin >> n;
	}

    Solution solution;
	TreeNode* root = solution.sortedArrayToBST(nums);

	printNode(root);

    return 0;
}
