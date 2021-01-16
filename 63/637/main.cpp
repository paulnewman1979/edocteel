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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root != NULL) {
            sumOfLevel(root, 0);
        }
        for (int i = 0; i < sum.size(); ++i) {
            sum[i] /= count[i];
        }
        return sum;
    }

private:
    void sumOfLevel(TreeNode* root, const int level) {
        if (level == sum.size()) {
            sum.push_back(root->val);
            count.push_back(1);
        } else {
            sum[level] += root->val;
            ++count[level];
        }
        if (root->left) sumOfLevel(root->left, level + 1);
        if (root->right) sumOfLevel(root->right, level + 1);
    }

private:
    vector<int> count;
    vector<double> sum;
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    vector<double> ret = solution.averageOfLevels(root);

    // output
    Output(ret);

    return 0;
}
