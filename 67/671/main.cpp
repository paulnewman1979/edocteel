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
    int findSecondMinimumValue(TreeNode* root) {
        if (root->left == NULL) return -1;
        least1 = INT_MAX;
        least2 = INT_MAX;
        findSecondMinimumValueSub(root);
        return ((least1 == least2) || (least2 == INT_MAX)) ? -1 : (least2 + 1);
    }

private:
    void findSecondMinimumValueSub(TreeNode* root) {
        int value = root->val - 1;
        if (value < least2) {
            if (value < least1) {
                least2 = least1;
                least1 = value;
                //cout << root->val << " " << least1 << " " << least2 << endl;
            } else if (value > least1) {
                least2 = value;
                //cout << root->val << " " << least1 << " " << least2 << endl;
            }
        }
        if (root->left != NULL) {
            findSecondMinimumValueSub(root->left);
            findSecondMinimumValueSub(root->right);
        }
    }
    
private:
    int least1;
    int least2;
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    int ret = solution.findSecondMinimumValue(root);

    // output
    Output(ret);

    return 0;
}
