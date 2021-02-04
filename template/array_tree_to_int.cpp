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
        return 0;
    }
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
