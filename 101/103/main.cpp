#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

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
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > levels;
        int level = 0;
        if (NULL != root) {
            levels.push_back(vector<int>());
            levels[level].push_back(root->val);

            insertLevel(root->left, level + 1, levels);
            insertLevel(root->right, level + 1, levels);
        }

        for (level=1; level<levels.size(); level += 2) {
            reverse(levels[level]);
        }

        return levels;
    }

    void insertLevel(TreeNode* root, const int level, vector< vector<int> >& levels)
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

    void reverse(vector<int>& curLevel)
    {
        int i = 0;
        int j = curLevel.size() - 1;
        int tmp;
        while (i < j) {
            tmp = curLevel[i];
            curLevel[i] = curLevel[j];
            curLevel[j] = tmp;
            ++ i;
            -- j;
        }
    }
};

int main(int argc, char* argv[])
{
    TreeNode a1(3);
	TreeNode a21(9);
	TreeNode a22(20);
	TreeNode a31(15);
	TreeNode a32(7);
	
	a1.left = &a21;
	a1.right = &a22;
	a22.left = &a31;
	a22.right = &a32;

	Solution solution;
	vector< vector<int> > results = solution.zigzagLevelOrder(&a1);

	int i;
	int j;
	for (i=0; i<results.size(); ++i) {
		for (j=0; j<results[i].size(); ++j) {
			cout << results[i][j] << ",";
		}
		cout << endl;
	}
}
