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
        return 0;
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
