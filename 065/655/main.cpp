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
        height = 0;
        getMaxHeight(root, 0);
        int i, size = 0;
        for (i = 0; i <= height; ++i) {
            size = (size<<1) + 1;
        }
        vector<vector<string>> ret(height + 1, vector<string>(size, ""));
        markTree(root, ret, 0, size / 2, size / 2);

        return ret;
    }

private:
    int height;

    void getMaxHeight(TreeNode* root,
            const int level) {
        if ((root->left == NULL) && (root->right == NULL)) {
            if (level > height) {
                height = level;
            }
        } else {
            if (root->left) {
                getMaxHeight(root->left, level + 1);
            }
            if (root->right) {
                getMaxHeight(root->right, level + 1);
            }
        }
    }

    void markTree(TreeNode* root,
            vector<vector<string>>& ret,
            const int level,
            const int middle,
            const int width) {
        ret[level][middle] = to_string(root->val);
        if (root->left) {
            markTree(root->left, ret, level + 1,
                    (middle + middle - width - 1) / 2,
                    width / 2);
        }
        if (root->right) {
            markTree(root->right, ret, level + 1,
                    (middle + middle + width + 1) / 2,
                    width / 2);
        }
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
    int i, j;
    for (i = 0; i < ret.size(); ++i) {
        for (j = 0; j < ret[i].size(); ++j) {
            cout << "\"" << ret[i][j] << "\" ";
        }
        cout << endl;
    }

    return 0;
}
