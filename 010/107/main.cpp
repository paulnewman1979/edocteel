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
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        vector< vector<int> > levels;

        pushLevel(levels, root, 0);

        if (levels.size() > 1) {
            int max = levels.size() - 1;
            for (int i=0; i < max - i; ++i) {
                levels[i].swap(levels[max - i]);
            }
        }

        return levels;
    }

    void pushLevel(vector< vector<int> >& levels, TreeNode* root, int level) {
        if (NULL == root) {
            return;
        }

        if (levels.size() <= level) {
            vector<int> level;
            levels.push_back(level);
        }
        levels[level].push_back(root->val);

        pushLevel(levels, root->left, level + 1);
        pushLevel(levels, root->right, level + 1);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

    Solution solution;
    vector< vector<int> > results = solution.levelOrderBottom(root);
	for (int i=0; i<results.size(); ++i) {
		for (int j=0; j<results[i].size(); ++j) {
			cout << results[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}
