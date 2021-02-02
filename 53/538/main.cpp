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
    TreeNode* convertBST(TreeNode* root) {
        if (NULL != root) {
            convertBST(root, 0);
        }
        return root;
    }

private:
    int convertBST(TreeNode* root, int otherSum) {
        if (root->right) root->val += convertBST(root->right, otherSum);
        int sum = root->val + (root->left ? convertBST(root->left, root->val + otherSum) : 0);
        root->val += otherSum;
        return sum;
    }
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    TreeNode* ret = solution.convertBST(root);

    // output 2
    Output(ret);

    return 0;
}
