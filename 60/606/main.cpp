#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

typedef BaseTreeNode<int> TreeNode;

class Solution {
public:
    string tree2str(TreeNode* t) {
        if (NULL == t) return "";
        stringstream ss;
        tree2str(t, ss);
        return ss.str();
    }

private:
    void tree2str(TreeNode* t, stringstream& ss) {
        ss << t->val;
        if (t->left == NULL) {
            if (t->right != NULL) {
                ss << "()(";
                tree2str(t->right, ss);
                ss << ")";
            }
        } else {
            ss << "(";
            tree2str(t->left, ss);
            ss << ")";
            if (t->right != NULL) {
                ss << "(";
                tree2str(t->right, ss);
                ss << ")";
            }
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
    string ret = solution.tree2str(root);

    // output
    Output(ret);

    return 0;
}
