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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root) {
            string path = to_string(root->val);
            if (root->left) {
                binaryTreePath(root->left, path);
                if (root->right) binaryTreePath(root->right, path);
            } else if (root->right) {
                binaryTreePath(root->right, path);
            } else {
                results.push_back(path);
            }
        }
        return results;
    }

private:
    void binaryTreePath(const TreeNode* root, const string& path) {
        static const string pointer("->");
        string newPath = path + pointer + to_string(root->val);
        if (root->left) {
            binaryTreePath(root->left, newPath);
            if (root->right) {
                binaryTreePath(root->right, newPath);
            }
        } else if (root->right) {
            binaryTreePath(root->right, newPath);
        } else {
            results.push_back(newPath);
        }
    }

private:
    vector<string> results;
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
    vector<string> results = solution.binaryTreePaths(root);
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }

    //unsigned index = 1;
    //printNode(root, 0, index);

    clearTree(root);

    return 0;
}
