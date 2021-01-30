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
    int findBottomLeftValue(TreeNode* root) {
        findBottomLeftValue(root, 0);
        return mostLeft.back();
    }

private:
    void findBottomLeftValue(TreeNode* root, int level) {
        if (mostLeft.size() <= level) {
            mostLeft.push_back(root->val);
        } else {
            mostLeft[level] = root->val;
        }
        if (root->right) findBottomLeftValue(root->right, level + 1);
        if (root->left) findBottomLeftValue(root->left, level + 1);
    }

private:
    vector<int> mostLeft;
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    int ret = solution.findBottomLeftValue(root);

    // output
    Output(ret);

    return 0;
}
