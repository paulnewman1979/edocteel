#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unordered_map>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

typedef BaseTreeNode<int> TreeNode;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        if (NULL == root) return ret;

        unordered_map<int, int> numCount;

        findMode(root, numCount);
        unordered_map<int, int>::iterator iter = numCount.begin();
        int maxCount = 0;
        while (iter != numCount.end()) {
            if (iter->second > maxCount) maxCount = iter->second;
            ++iter;
        }
        iter = numCount.begin();
        while (iter != numCount.end()) {
            if (iter->second == maxCount) ret.push_back(iter->first);
            ++iter;
        }
        return ret;
    }

private:
    void findMode(TreeNode* root, unordered_map<int, int>& numCount) {
        numCount[root->val]++;
        if (root->left) findMode(root->left, numCount);
        if (root->right) findMode(root->right, numCount);
    }
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    vector<int> ret = solution.findMode(root);

    // output
    Output(ret);

    return 0;
}
