#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

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
    void flatten(TreeNode* root) {
		if (NULL == root) {
			return;
		}

		TreeNode* tail = flatten(root->right, NULL);
		root->right = flatten(root->left, tail);
		root->left = NULL;
	}

	TreeNode* flatten(TreeNode* root, TreeNode* tail) {
		if (NULL == root) {
			return tail;
		}

		tail = flatten(root->right, tail);
		tail = flatten(root->left, tail);
		root->right = tail;
		root->left = NULL;
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

void printRight(TreeNode* root) {
	TreeNode* cur = root;
	while (NULL != cur) {
		cout << cur->val << endl;
		cur = cur->right;
	}
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
	solution.flatten(root);

	printRight(root);

	return 0;
}
