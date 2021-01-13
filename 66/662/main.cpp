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
    int widthOfBinaryTree(TreeNode* root) {
        if (NULL == root) return 0;
        int level = 0;
        unsigned long long int num = 0;
        checkMost(root, level, num);
        level = 1;
        num = 1;
        while ((level < mostLeft.size()) && (level < mostRight.size())) {
            if (mostRight[level] - mostLeft[level] + 1 > num) {
                num = mostRight[level] - mostLeft[level] + 1;
            }
            ++level;
        }
        return num;
    }

private:
    void checkMost(const TreeNode* root,
            const int level,
            const unsigned long long int num) {
        if (level >= mostLeft.size()) {
            mostLeft.push_back(num);
        } else if (num < mostLeft[level]) {
            mostLeft[level] = num;
        }

        if (level >= mostRight.size()) {
            mostRight.push_back(num);
        } else if (num > mostRight[level]) {
            mostRight[level] = num;
        }

        if (root->left) {
            checkMost(root->left, level + 1, (num<<1));
        }
        if (root->right) {
            checkMost(root->right, level + 1, (num<<1) + 1);
        }
    }

private:
    vector<unsigned long long int> mostLeft;
    vector<unsigned long long int> mostRight;
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    int ret = solution.widthOfBinaryTree(root);

    // output
    Output(ret);

    return 0;
}
