#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

// Definition for a Node.
typedef ArrayTreeNode<int> Node;

class Solution {
public:
    vector<int> preorder(Node* root) {
        int i;
        vector<int> ret;
        if (NULL != root) {
            vector<Node*> stack;
            Node* cur;
            stack.push_back(root);
            while (stack.size() > 0) {
                cur = stack.back();
                stack.pop_back();
                ret.push_back(cur->val);
                for (i = cur->children.size() - 1; i >= 0; --i) {
                    stack.push_back(cur->children[i]);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    Node* root;
    Input(root);

    // solution
    Solution solution;
    vector<int> ret;
    ret = solution.preorder(root);

    // output
    Output(ret);

    return 0;
}
