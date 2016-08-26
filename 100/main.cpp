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
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if ((NULL == p) && (NULL == q)) {
			return true;
		} else if ((NULL != p) && (NULL != q) &&
			(p->val() == q->val()) &&
			isSameTree(p->left, q->left) &&
			isSameTree(p->right, q->right)) {
			return true;
		}
		return false;
    }
};

