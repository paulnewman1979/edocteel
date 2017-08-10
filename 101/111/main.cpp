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
    int minDepth(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        
        if (NULL == root->left) {
            if (NULL == root->right) {
                return 1;
            } else {
                return minDepth(root->right) + 1;
            }
        } else if (NULL == root->right) {
            return minDepth(root->left) + 1;
        } else {
            int lh = minDepth(root->left) + 1;
            int rh = minDepth(root->right) + 1;
            return ((lh<rh)?lh:rh);
        }
    }
};

