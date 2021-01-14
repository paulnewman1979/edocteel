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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return 0;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> nums;
    Input(nums);

    // solution
    Solution solution;
    TreeNode* ret = solution.constructMaximumBinaryTree(nums);

    // output
    Output(ret);

    return 0;
}
