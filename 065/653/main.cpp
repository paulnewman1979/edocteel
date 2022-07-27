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
    bool findTarget(TreeNode* root, int k) {
        if (NULL == root) return false;

        this->k = k;
        return findTarget(root);
    }

private:
    bool findTarget(TreeNode* root) {
        if (expected.find(root->val) != expected.end()) {
            return true;
        } else {
            expected.insert(k - root->val);
            if (root->left) {
                if (findTarget(root->left)) return true;
            }
            if (root->right) {
                if (findTarget(root->right)) return true;
            }
        }
        return false;
    }

private:
    unordered_set<int> expected;
    int k;
};

int main(int argc, char* argv[])
{
    // input
    int k;
    TreeNode* root;
    Input(k);
    Input(root);

    // solution
    Solution solution;
    bool ret = solution.findTarget(root, k);

    // output
    Output(ret);

    return 0;
}
