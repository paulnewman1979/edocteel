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
    int getMinimumDifference(TreeNode* root) {
        minDiff = INT_MAX;
        int min, max;
        getMinMax(root, min, max);
        return minDiff;
    }

private:
    void getMinMax(TreeNode* root, int& min, int& max) {
        int tmp = -1;
        if (root->left) {
            getMinMax(root->left, min, tmp);
            if ((tmp != -1) && (root->val - tmp < minDiff)) {
                minDiff = root->val - tmp;
            }
        } else {
            min = root->val;
        }

        if (root->right) {
            tmp = -1;
            getMinMax(root->right, tmp, max);
            if ((tmp != -1) && (tmp - root->val < minDiff)) {
                minDiff = tmp - root->val;
            }
        } else {
            max = root->val;
        }
    }

private:
    int minDiff;
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    int ret = solution.getMinimumDifference(root);

    // output
    Output(ret);

    return 0;
}
