#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result;
        if (findKthSmallest(root->left, k, result)) {
            return result;
        } else if (k - result == 1) {
            return root->val;
        } else {
            findKthSmallest(root->right, k - result - 1, result);
            return result;
        }
    }

    bool findKthSmallest(const TreeNode* root, const int k, int &result) {
        if (NULL == root) {
            result = 0;
            return false;
        } else {
            int leftResult = 0;
            int rightResult = 0;
            if (findKthSmallest(root->left, k, leftResult)) {
                result = leftResult;
                return true;
            } else if (k - leftResult == 1) {
                result = root->val;
                return true;
            } else if (findKthSmallest(root->right, k - leftResult - 1, rightResult)) {
                result = rightResult;
                return true;
            } else {
                result = leftResult + rightResult + 1;
                return false;
            }
        }
    }
};

void composeTree(TreeNode* root, const vector<int>& nodes, int& index) {
    if (nodes[index] != -999998) {
        root->left = new TreeNode(nodes[index]);
        ++ index;
        composeTree(root->left, nodes, index);
    } else {
        ++ index;
    }

    if (nodes[index] != -999998) {
        root->right = new TreeNode(nodes[index]);
        ++ index;
        composeTree(root->right, nodes, index);
    } else {
        ++ index;
    }
}


TreeNode* composeTree(const vector<int>& nodes) {
    if (nodes.size() == 0) {
        return NULL;
    }

    TreeNode* root = new TreeNode(nodes[0]);
    int index = 1;

    composeTree(root, nodes, index);

    return root;
}


void printNode(TreeNode* root) {
    if (NULL == root) {
        return;
    }

    cout << root->val << endl;
    printNode(root->left);
    printNode(root->right);
}


int main(int argc, char* argv[])
{
    int n;
    int k;
    vector<int> nodes;

    cin >> k;
    cin >> n;
    while (n != -999999) {
        nodes.push_back(n);
        cin >> n;
    }

    TreeNode* root = composeTree(nodes);
        
    Solution solution;
    int result = solution.kthSmallest(root, k);

    //printNode(root);
    cout << result << endl;

    return 0;
}
