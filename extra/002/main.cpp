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
    string val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(string x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> action(TreeNode* root) {
        vector<string> results;
        string result;
        vector<TreeNode*> stack;
        TreeNode* cur;

        cur = root;
        stack.push_back(cur);
        result.append(cur->val);
        while (cur->left || cur->right) {
            if (cur->left) {
                cur = cur->left;
                stack.push_back(cur);
                result.append(cur->val);
            } else {
                cur = cur->right;
                stack.push_back(cur);
                result.append(cur->val);
            }
        }
        results.push_back(result);

        cur = stack.back();
        stack.pop_back();
        result.pop_back();
        while (stack.size() > 0) {
            if (cur == stack.back()->left) {
                if (stack.back()->right) {
                    cur = stack.back()->right;
                    stack.push_back(cur);
                    result.append(cur->val);
                    while (cur->left || cur->right) {
                        if (cur->left) {
                            cur = cur->left;
                            stack.push_back(cur);
                            result.append(cur->val);
                        } else {
                            cur = cur->right;
                            stack.push_back(cur);
                            result.append(cur->val);
                        }
                    }
                    results.push_back(result);
                }
            }
            cur = stack.back();
            stack.pop_back();
            result.pop_back();
        }

        return results;
    }
};

TreeNode* composeTree() {
    unsigned int n;
    unsigned int i;
    unsigned int index;
    string value;
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
                nodes[leftIndex] = new TreeNode("");
            }
            nodes[i]->left = nodes[leftIndex];
        }
        if (rindex != std::string("n")) {
            rightIndex = atoi(rindex.c_str());
            assert(rightIndex < n);
            if (nodes[rightIndex] == NULL) {
                nodes[rightIndex] = new TreeNode("");
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
    TreeNode* root = composeTree();
 
    Solution solution;
    vector<string> results;
    results = solution.action(root);
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }

    //unsigned index = 1;
    //printNode(root, 0, index);

    clearTree(root);

    return 0;
}
