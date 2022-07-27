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
    int maxDepth(Node* root) {
        if (NULL == root) return 0;
        if (root->children.size() == 0) return 1;
        maxD = 0;
        for (const auto& c : root->children) {
            count(c, 2);
        }
        return maxD;
    }

private:
    void count(Node* root, int level) {
        if (root->children.size() == 0) {
            if (level > maxD) maxD = level;
        } else {
            for (const auto& c : root->children) {
                count(c, level + 1);
            }
        }
    }

private:
    int maxD;
};

int main(int argc, char* argv[])
{
    // input
    Node* root;
    Input(root);
    Output(root);

    // solution
    Solution solution;
    int ret = solution.maxDepth(root);

    // output
    Output(ret);

    return 0;
}
