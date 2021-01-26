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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v, root, NULL);
            return newRoot;
        }

        addOneRow(root, v, d, 1);

        return root;
    }

private:
    void addOneRow(TreeNode* root, int v, int d, int curD) {
        if (curD + 1 == d) {
            TreeNode* leftSon = new TreeNode(v, root->left, NULL);
            TreeNode* rightSon = new TreeNode(v, NULL, root->right);
            root->left = leftSon;
            root->right = rightSon;
        } else {
            if (root->left) addOneRow(root->left, v, d, curD + 1);
            if (root->right) addOneRow(root->right, v, d, curD + 1);
        }
    }
};

int main(int argc, char* argv[])
{
    // input
    int v, d;
    TreeNode* root;
    Input(v);
    Input(d);
    Input(root);

    // solution
    Solution solution;
    TreeNode* ret = solution.addOneRow(root, v, d);

    // output 2
    Output(ret);

    return 0;
}
