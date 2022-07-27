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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector< vector<TreeNode*> > results;
        results.push_back(vector<TreeNode*>());
        if (N % 2 == 0) {
            return results[0];
        }

        results[0].push_back(new TreeNode(0));
        if (N == 1) {
            return results[0];
        }

        results.push_back(vector<TreeNode*>());
        TreeNode* cur = new TreeNode(0);
        cur->left = new TreeNode(0);;
        cur->right = new TreeNode(0);
        results[1].push_back(cur);
        if (N == 3) {
            return results[1];
        }

        int n = (N - 1) / 2;
        int i, j, k, l, m;
        for (i = 2; i <= n; ++i) {
            results.push_back(vector<TreeNode*>());
            for (j = 0; j <= i - 1; ++j) {
                k = i - 1 - j;
                for (l = 0; l < results[j].size(); ++l) {
                    for (m = 0; m < results[k].size(); ++m) {
                        cur = new TreeNode(0);
                        cur->left = results[j][l];
                        cur->right = results[k][m];
                        results[i].push_back(cur);
                    }
                }
            }
        }

        return results[n];
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
    vector<TreeNode*> result = solution.allPossibleFBT(N);
    for (int i = 0; i < result.size(); ++i) {
        unsigned index = 1;
        printNode(result[i], 0, index);
        cout << endl;
        //clearTree(result[i]);
    }

    return 0;
}
