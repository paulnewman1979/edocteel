#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

typedef BaseTreeNode<int> TreeNode;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if (NULL != root) {
            getLargestValues(root, ret, 0);
        }
        return ret;
    }

private:
    void getLargestValues(TreeNode* root, vector<int>& ret, int level) {
        if (ret.size() <= level) {
            ret.push_back(root->val);
        } else if (ret[level] < root->val) {
            ret[level] = root->val;
        }
        if (root->left) getLargestValues(root->left, ret, level + 1);
        if (root->right) getLargestValues(root->right, ret, level + 1);
    }
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    vector<int> ret = solution.largestValues(root);

    // output
    Output(ret);

    return 0;
}
