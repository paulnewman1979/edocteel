#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if (NULL == root) {
			return true;
		}

		return isSymmetric(root->left, root->right);
    }

	bool isSymmetric(TreeNode* left, TreeNode* right) {
		if (NULL == left) {
			return (NULL == right)?true:false;
		} else if ((NULL == right) ||
			(left->val != right->val) ) {
			return false;
		}

		return isSymmetric(left->left, right->right) &&
				isSymmetric(left->right, right->left);
	}
};
