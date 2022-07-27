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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (NULL == root1) {
            return NULL == root2;
        } else if (NULL == root2) {
            return false;
        }

        int i;

        vector<int> leafValue1;
        vector<int> leafValue2;
        listLeaf(root1, leafValue1);
        listLeaf(root2, leafValue2);

        /*
        for (i = 0; i < leafValue1.size(); ++i) {
            cout << leafValue1[i] << endl;
        }
        cout << endl;

        for (i = 0; i < leafValue2.size(); ++i) {
            cout << leafValue2[i] << endl;
        }
        cout << endl;
        */

        if (leafValue1.size() != leafValue2.size()) return false;
        for (i = 0; i < leafValue1.size(); ++i) {
            if (leafValue1[i] != leafValue2[i]) return false;
        }
        return true;
    }

 private:
    void listLeaf(TreeNode* root, vector<int>& leafValue) {
        if (root->left) {
            listLeaf(root->left, leafValue);
            if (root->right) {
                listLeaf(root->right, leafValue);
            }
        } else if (root->right) {
            listLeaf(root->right, leafValue);
        } else {
            leafValue.push_back(root->val);
        }
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
    TreeNode* root1 = composeTree();
    TreeNode* root2 = composeTree();
        
    Solution solution;
    cout << (solution.leafSimilar(root1, root2) ? "true" : "false") << endl;

    //unsigned index = 1;
    //printNode(root, 0, index);

    clearTree(root1);
    clearTree(root2);

    return 0;
}
