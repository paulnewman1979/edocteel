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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ret;
        if (NULL != root) {
            _mostFreq = 0;
            getSum(root, ret);
        }
        return ret;
    }

private:
    int getSum(TreeNode* root, vector<int>& ret) {
        int leftSum = 0, rightSum = 0, sum = root->val;
        if (root->left) leftSum = getSum(root->left, ret);
        if (root->right) rightSum = getSum(root->right, ret);
        sum += leftSum + rightSum;
        _sumFreq[sum]++;
        if (_sumFreq[sum] > _mostFreq) {
            ret.clear();
            ret.push_back(sum);
            _mostFreq = _sumFreq[sum];
        } else if (_sumFreq[sum] == _mostFreq) {
            ret.push_back(sum);
        }
        return sum;
    }

private:
    unordered_map<int, int> _sumFreq;
    int _mostFreq;
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    vector<int> ret = solution.findFrequentTreeSum(root);

    // output
    Output(ret);

    return 0;
}
