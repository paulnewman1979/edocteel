#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

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
        unordered_set<int> route;
        return checkLCA(root, p, q, result, route);
    }

    TreeNode* checkLCA(TreeNode* root,
                        TreeNode* p,
                        TreeNode* q,
                        int& result,
                        unordered_set<int>& route) {
        if (NULL == root) return NULL;
        if (route.count((unsigned long)root) > 0) return NULL;
        route.insert((unsigned long)root);
        TreeNode *res = NULL;
        int leftResult = 0;
        if (NULL != (res = checkLCA(root->left, p, q, leftResult, route))) {
            return res;
        }
        int rightResult = 0;
        if (NULL != (res = checkLCA(root->right, p, q, rightResult, route))) {
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
        route.erase((unsigned long)root);
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

    int pVal;
    int qVal;
    cin >> pVal;
    cin >> qVal;

    cin >> n;
    while (n != -999999) {
        nodes.push_back(n);
        cin >> n;
    }

    TreeNode *root = composeTree(nodes);
    TreeNode *p = new TreeNode(pVal);
    TreeNode *q = new TreeNode(qVal);
        
    Solution solution;
    TreeNode* res = solution.lowestCommonAncestor(root, p, q);

    cout << res->val << endl;
    //printNode(root);

    return 0;
}
