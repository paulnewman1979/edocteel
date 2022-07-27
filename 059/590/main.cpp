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
    vector<int> postorder(Node* root) {
        vector<int> ret;
        if (NULL != root) postorder(root, ret);
        return ret;
    }
    
private:
    void postorder(Node* root, vector<int>& ret) {
        if (root->children.size() > 0) {
            for (auto& c: root->children) {
                if (c != NULL) postorder(c, ret);
            }
        }
        ret.push_back(root->val);
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
    ret = solution.postorder(root);

    // output
    Output(ret);

    return 0;
}
