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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int result = 0;
        return checkLCA(root, p, q, result);
    }

    TreeNode* checkLCA(TreeNode* root, TreeNode* p, TreeNode* q, int& result) {
        if (NULL == root) return NULL;

        TreeNode *res = NULL;
        int leftResult = 0;
        if (NULL != (res = checkLCA(root->left, p, q, leftResult))) {
            return res;
        }
        int rightResult = 0;
        if (NULL != (res = checkLCA(root->right, p, q, rightResult))) {
            return res;
        }
        result |= leftResult;
        result |= rightResult;
        if (root == p) {
            result |= 1;
        } else if (root == q) {
            result |= 2;
        }
        if (3 == result) {
             return root;
        }
        return NULL;
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
    vector<int> nodes;

    cin >> n;
    while (n != -999999) {
        nodes.push_back(n);
        cin >> n;
    }

    TreeNode* root = composeTree(nodes);
        
    Solution solution;
    TreeNode* res = solution.lowestCommonAncestor(root);

    cout << res->val << endl;
    //printNode(root);

    return 0;
}
