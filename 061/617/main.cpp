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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (NULL == t1) return t2;
        else if (NULL == t2) return t1;
        else {
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            t1->val += t2->val;
            return t1;
        }
    }
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* t1;
    TreeNode* t2;
    Input(t1);
    Input(t2);

    // solution
    Solution solution;
    TreeNode* ret = solution.mergeTrees(t1, t2);

    // output 2
    Output(ret);

    return 0;
}
