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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        int level = 0;
        if (NULL != root) {
            levels.push_back(vector<int>());
            levels[level].push_back(root->val);

            insertLevel(root->left, level + 1, levels);
            insertLevel(root->right, level + 1, levels);
        }
        
        return levels;
    }

    void insertLevel(TreeNode* root, const int level, vector<vector<int>>& levels)
    {
        if (NULL != root) {
            if (levels.size() <= level) {
                levels.push_back(vector<int>());
            }
            levels[level].push_back(root->val);
            insertLevel(root->left, level + 1, levels);
            insertLevel(root->right, level + 1, levels);
        }
    }
};

