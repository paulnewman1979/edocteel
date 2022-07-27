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
    int diameterOfBinaryTree(TreeNode* root) {
        if (NULL == root) return 0;
        diameter = 0;
        int length = checkDiameter(root);
        --length;
        if (length > diameter) diameter = length;
        return diameter;
    }

private:
    int checkDiameter(TreeNode* root) {
        int leftLength = (root->left) ? checkDiameter(root->left) : 0;
        int rightLength = (root->right) ? checkDiameter(root->right) : 0;
        if (leftLength + rightLength > diameter) {
            diameter = leftLength + rightLength;
        }
        return (leftLength > rightLength) ? (leftLength + 1) : (rightLength + 1);
    }

private:
    int diameter;
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    int ret = solution.diameterOfBinaryTree(root);

    // output
    Output(ret);

    return 0;
}
