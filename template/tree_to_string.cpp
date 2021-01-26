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
    string tree2str(TreeNode* t) {
        string ret;
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    string ret = solution.tree2str(root);

    // output
    Output(ret);

    return 0;
}
