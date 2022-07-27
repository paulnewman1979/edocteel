#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

typedef BaseTreeNode<int> TreeNode;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = NULL;
        if (nums.size() == 0) return root;

        orderedNums = nums;
        for (int i = 0; i < nums.size(); ++i) {
            numToPos[nums[i]] = i;
        }
        numIndex = 0;
        sort(orderedNums.begin(), orderedNums.end(), greater<int>());

        root = constructTree(nums, 0, nums.size());

        return root;
    }

private:
    TreeNode* constructTree(const vector<int>& nums,
            const int start,
            const int end) {
        int i = numIndex;
        int num = orderedNums[i];
        while ((num == INT_MAX) ||
                (numToPos[num] < start) ||
                (numToPos[num] >= end)) {
            ++i;
            num = orderedNums[i];
        }
        int pos = numToPos[num];
        TreeNode* newNode = new TreeNode(num);
        orderedNums[i] = INT_MAX;
        while ((numIndex < orderedNums.size()) &&
                (orderedNums[numIndex] == INT_MAX)) {
            ++numIndex;
        }
        if (start < pos) {
            newNode->left = constructTree(nums, start, pos);
        }
        if (pos + 1 < end) {
            newNode->right = constructTree(nums, pos + 1, end);
        }
        return newNode;
    }

private:
    unordered_map<int, int> numToPos;
    vector<int> orderedNums;
    int numIndex;
};

int main(int argc, char* argv[])
{
    // input
    vector<int> nums;
    Input(nums);

    // solution
    Solution solution;
    TreeNode* ret = solution.constructMaximumBinaryTree(nums);

    // output
    Output(ret);

    return 0;
}
