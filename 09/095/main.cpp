#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) { return vector<TreeNode*>(0); }
        vector<vector<TreeNode*>> result(n + 1);
        int i, j;
        result[0].push_back(NULL);
        for (i = 1; i <= n; ++i) {
            for (j = 0; j < i; ++j) {
                for (auto p: result[j]) {
                    for (auto q: result[i - j - 1]) {
                        TreeNode* newNode = new TreeNode(0);
                        int start = 1;
                        newNode->left = clone(p, start);
                        newNode->val = start++;
                        newNode->right = clone(q, start);
                        result[i].push_back(newNode);
                    }
                }
            }
        }
        return result[n];
    }

private:
    TreeNode* clone(TreeNode* root, int& start) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* newRoot = new TreeNode(0);
        if (root->left) {
            newRoot->left = clone(root->left, start);
        }
        newRoot->val = start++;
        if (root->right) {
            newRoot->right = clone(root->right, start);
        }
        return newRoot;
    }
};

TreeNode* composeTree() {
    unsigned int n;
    unsigned int i;
    unsigned int index;
    int value;
    string lindex;
    string rindex;
    unsigned int leftIndex;
    unsigned int rightIndex;

    cin >> n;
    vector<TreeNode*> nodes(n, NULL);
    i = 0;
    while (i < n) {
        cin >> index;
        cin >> value;
        cin >> lindex;
        cin >> rindex;
        assert(i == index);

        if (nodes[i] == NULL) {
            nodes[i] = new TreeNode(value);
        } else {
            nodes[i]->val = value;
        }
        if (lindex != std::string("n")) {
            leftIndex = atoi(lindex.c_str());
            assert(leftIndex < n);
            if (nodes[leftIndex] == NULL) {
                nodes[leftIndex] = new TreeNode(0);
            }
            nodes[i]->left = nodes[leftIndex];
        }
        if (rindex != std::string("n")) {
            rightIndex = atoi(rindex.c_str());
            assert(rightIndex < n);
            if (nodes[rightIndex] == NULL) {
                nodes[rightIndex] = new TreeNode(0);
            }
            nodes[i]->right = nodes[rightIndex];
        }
        ++i;
    }

    return nodes[0];
}

void printNode(TreeNode* root, unsigned int rootIndex, unsigned int& index) {
    unsigned int leftIndex = index;
    cout << rootIndex << "\t" << root->val;
    if (root->left) {
        ++index;
        cout << "\t" << leftIndex;
    } else {
        cout << "\tn";
        leftIndex = 0;
    }
    unsigned int rightIndex = index;
    if (root->right) {
        ++index;
        cout << "\t" << rightIndex;
    } else {
        cout << "\tn";
        rightIndex = 0;
    }
    cout << endl;

    if (leftIndex != 0) {
        printNode(root->left, leftIndex, index);
    }
    if (rightIndex != 0) {
        printNode(root->right, rightIndex, index);
    }
}

void clearTree(TreeNode* root) {
    if (NULL != root) {
        clearTree(root->left);
        clearTree(root->right);
    }
    delete root;
}

int main(int argc, char* argv[])
{
    int N;
        
    Solution solution;
    cin >> N;
    vector<TreeNode*> result = solution.generateTrees(N);
    for (int i = 0; i < result.size(); ++i) {
        unsigned index = 1;
        printNode(result[i], 0, index);
        cout << endl;
        //clearTree(result[i]);
    }

    return 0;
}
