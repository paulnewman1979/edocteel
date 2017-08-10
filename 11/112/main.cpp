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
    bool hasPathSum(TreeNode* root, int sum) {
		if (NULL == root) {
			return false;
		}
		return hasPathSum(root, sum, 0);
    }

	bool hasPathSum(TreeNode* root, int sum, int curSum) {
		if (root->left == NULL) {
			if (root->right == NULL) {
				return (sum == curSum + root->val)?true:false;
			} else {
				return hasPathSum(root->right, sum, curSum + root->val);
			}
		} else if (root->right == NULL) {
			return hasPathSum(root->left, sum, curSum + root->val);
		} else {
			return (hasPathSum(root->left, sum, curSum + root->val) ||
				hasPathSum(root->right, sum, curSum + root->val))?true:false;
		}
	}
};

int main(int argc, char* argv[]) {
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);

	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int sum = 22;
	Solution solution;
	cout << ((solution.hasPathSum(root, sum))?"true":"false") << endl;
}
