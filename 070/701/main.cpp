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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (NULL == root) {
            root = new TreeNode(val);
            return root;
        } else {
            insertBST(root, val);
        }
        return root;
    }

private:
    void insertBST(TreeNode* root, int val) {
        if (val > root->val) {
            if (root->right == NULL) {
                root->right = new TreeNode(val);
            } else {
                insertBST(root->right, val);
            }
        } else {
            if (root->left == NULL) {
                root->left = new TreeNode(val);
            } else {
                insertBST(root->left, val);
            }
        }
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
    TreeNode* ret = solution.insertIntoBST(root, value);

    // output 2
    Output(ret);

    return 0;
}
