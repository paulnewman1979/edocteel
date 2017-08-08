#include <iostream>
#include <queue>

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
    TreeNode* invertTree(TreeNode* root) {
        if (NULL != root) {
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
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
    root = solution.invertTree(root);

    printNode(root);

    return 0;

}
