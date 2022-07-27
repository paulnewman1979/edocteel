#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unordered_map>

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int i = 0;
        for (i = 0; i < pre.size(); ++i) {
            postMap[post[i]] = i;
        }
        return constructFromPrePost(pre, post, 0, 0, pre.size());
    }

    TreeNode* constructFromPrePost(vector<int>& pre,
            vector<int>& post,
            int preS,
            int postS,
            int size)       // size > 0
    {
        //cout << "preS=" << preS << ", postS=" << postS << ", size=" << size << endl;
        switch(size) {
        case 0:
            return NULL;
        case 1:
            return new TreeNode(pre[preS]);
        default:
            TreeNode* cur = new TreeNode(pre[preS]);
            int leftSize = postMap[pre[preS + 1]] + 1 - postS;
            //cout << "left" << endl;
            cur->left = constructFromPrePost(pre, post, preS + 1, postS, leftSize);
            //cout << "right" << endl;
            cur->right = constructFromPrePost(pre, post, preS + 1 + leftSize, postS + leftSize, size - 1 - leftSize);
            return cur;
        }
    }

private:
    unordered_map<int, int> postMap;
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
    int n;
    int value;
    vector<int> values1;
    vector<int> values2;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values1.push_back(value);
        --n;
    }

    cin >> n;
    while (n > 0) {
        cin >> value;
        values2.push_back(value);
        --n;
    }

    Solution solution;
    TreeNode* root = solution.constructFromPrePost(values1, values2);
        
    unsigned index = 1;
    printNode(root, 0, index);

    clearTree(root);

    return 0;
}
