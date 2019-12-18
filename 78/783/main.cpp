#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

typedef MyTreeNode<int> TreeNode;

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int min = 0, max = INT_MAX;
        return minDiffInBST(root, min, max);
    }

private:
    int minDiffInBST(TreeNode* root, int& min, int& max) {
        int minDiff = INT_MAX, tmp, curMinDiff;
        if (root->left != NULL) {
            curMinDiff = minDiffInBST(root->left, min, tmp);
            minDiff = (root->val - tmp < curMinDiff) ? (root->val - tmp) : curMinDiff;
        } else {
            min = root->val;
        }

        if (root->right != NULL) {
            curMinDiff = minDiffInBST(root->right, tmp, max);
            if (curMinDiff < minDiff) minDiff = curMinDiff;
            if (tmp - root->val < minDiff) minDiff = tmp - root->val;
        } else {
            max = root->val;
        }

        return minDiff;
    }
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    int ret = solution.minDiffInBST(root);

    // output
    Output(ret);

    return 0;
}
