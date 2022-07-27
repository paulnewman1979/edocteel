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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        this->low = low;
        this->high = high;
        return trimBST(root);
    }

private:
    TreeNode* trimBST(TreeNode* root) {
        if (NULL == root) return NULL;
        else if (root->val < low) {
            return trimBST(root->right);
        } else if (root->val > high) {
            return trimBST(root->left);
        } else {
            root->left = trimBST(root->left);
            root->right = trimBST(root->right);
            return root;
        }
    }

private:
    int low;
    int high;
};

int main(int argc, char* argv[])
{
    // input
    int low, high;
    TreeNode* root;
    Input(low);
    Input(high);
    Input(root);

    // solution
    Solution solution;
    TreeNode* ret = solution.trimBST(root, low, high);

    // output 2
    Output(ret);

    return 0;
}
