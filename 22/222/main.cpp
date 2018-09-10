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
    int countNodes(TreeNode* root) {
        if (NULL == root) return 0;
        if (root->left == NULL && root->right == NULL) return 1;

        // 2^(height - 1) ~ 2^height - 1
        height = 1;
        TreeNode* cur = root->left;
        while (cur != NULL) {
            cur = cur->left;
            ++height;
        }

        int level = 1;
        int count = 0;
        isBalance(root, level, count);
        return count + (1<<(height - 1)) - 1;
    }

    bool isBalance(TreeNode* root, int level, int& count) {
        if (level + 1 < height) {
            if (isBalance(root->left, level + 1, count)) {
                return isBalance(root->right, level + 1, count);
            } else {
                return false;
            }
        } else {
            bool balance = true;
            if (root->left) {
                ++count;
            } else {
                balance = false;
            }
            if (root->right) {
                ++count;
            } else {
                balance = false;
            }
            return balance;
        }
    }

private:
    int height;
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
        leftIndex = 0;
    }
    unsigned int rightIndex = index;
    if (root->right) {
        ++index;
        cout << "\t" << rightIndex;
    } else {
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
    TreeNode* root = composeTree();
        
    Solution solution;
    cout << solution.countNodes(root) << endl;

    //unsigned index = 1;
    //printNode(root, 0, index);

    clearTree(root);

    return 0;
}
