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
    bool isBalanced(TreeNode* root) {
		if (NULL == root) {
			return true;
		}

		int lh;
		int rh;
		return isBalanced(root->left, lh) &&
				isBalanced(root->right, rh) &&
				(lh - rh <=1) &&
				(lh - rh >=-1);
    }

	bool isBalanced(TreeNode* root, int& height) {
		int lh;
		int rh;
		if (NULL == root) {
			height = 0;
			return true;
		}

		if (!isBalanced(root->left, lh) ||
			!isBalanced(root->right, rh) ||
			(lh - rh > 1) ||
			(lh - rh < -1) ) {
			return false;
		}

		height = (lh > rh)?lh+1:rh+1;
		return true;
	}
};

