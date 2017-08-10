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

        int height = 0;
        return isBalanced(root, height);
    }

    bool isBalanced(TreeNode* root, int& height) {
        int lh = 0;
        int rh = 0;
        if (root->left == NULL) {
            lh = 0;
        } else if (!isBalanced(root->left, lh)) {
            return false;
        }

        if (root->right == NULL) {
            rh = 0;
        } else if (!isBalanced(root->right, rh)) {
            return false;
        }

        if ((lh - rh > 1) ||
            (lh - rh < -1) ) {
            return false;
        }

        height = (lh > rh)?lh+1:rh+1;
        return true;
    }
};
