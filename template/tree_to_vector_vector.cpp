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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> ret;
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
    vector<vector<string>> ret = solution.printTree(root);

    // output
    Output(ret);

    return 0;
}
