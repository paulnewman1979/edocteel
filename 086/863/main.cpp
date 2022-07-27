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
    vector<int> distanceK(const TreeNode* root, const TreeNode* target, int K) {
        vector<int> result;

        vector<const TreeNode*> path;
        if (root == target) {
            distanceK(root, K, result);
            return result;
        }

        // find target and path
        findTarget(root, target, path);

        // check target sons
        distanceK(target, K, result);

        int subIndex = 0;
        int index = subIndex + 1;
        --K;
        while ((index < path.size()) && (K > 0)) {
            if (path[index]->left == path[subIndex]) {
                if (path[index]->right) {
                    distanceK(path[index]->right, K - 1, result);
                }
            } else {
                if (path[index]->left) {
                    distanceK(path[index]->left, K - 1, result);
                }
            }
            subIndex = index;
            ++index;
            --K;
        }
        if ((index < path.size()) && (K == 0)) {
            result.push_back(path[index]->val);
        }

        return result;
    }

private:
    bool findTarget(const TreeNode* root, const TreeNode* target, vector<const TreeNode*>& path) {
        if (root == target) {
            path.push_back(root);
            return true;
        } else if ((root->left) &&
                findTarget(root->left, target, path)) {
            path.push_back(root);
            return true;
        } else if ((root->right) &&
                findTarget(root->right, target, path)) {
            path.push_back(root);
            return true;
        }
        return false;
    }

    void distanceK(const TreeNode* root, int K, vector<int>& result) {
        //cout << "look up " << root->val << " K=" << K << endl;
        if (0 == K) {
            result.push_back(root->val);
        } else {
            if (root->left) {
                distanceK(root->left, K - 1, result);
            }
            if (root->right) {
                distanceK(root->right, K - 1, result);
            }
        }
    }
};

TreeNode* composeTree(int targetValue, TreeNode*& target) {
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
        if (i != index) {
            //cout << "i=" << i << ", index=" << index << endl;
            assert(i == index);
        }

        if (nodes[i] == NULL) {
            nodes[i] = new TreeNode(value);
            if (value == targetValue) target = nodes[i];
        } else {
            nodes[i]->val = value;
            if (value == targetValue) target = nodes[i];
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
    int K;
    int targetValue;

    cin >> K;
    cin >> targetValue;
    TreeNode* target = NULL;
    TreeNode* root = composeTree(targetValue, target);
        
    Solution solution;
    vector<int> result = solution.distanceK(root, target, K);

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    //unsigned index = 1;
    //printNode(root, 0, index);

    clearTree(root);

    return 0;
}
