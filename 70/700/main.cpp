#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <queue>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

typedef BaseTreeNode<int> TreeNode;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (NULL == root) return NULL;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        while (treeQueue.size() > 0) {
            TreeNode* cur = treeQueue.front();
            treeQueue.pop();
            if (cur->val == val) return cur;
            if (cur->left != NULL) treeQueue.push(cur->left);
            if (cur->right != NULL) treeQueue.push(cur->right);
        }
        return NULL;
    }
};

int main(int argc, char* argv[])
{
    // input
    int value;
    TreeNode* root;
    Input(value);
    Input(root);

    // solution
    Solution solution;
    TreeNode* ret = solution.searchBST(root, value);

    // output 2
    Output(ret);

    return 0;
}
