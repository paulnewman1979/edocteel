#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		vector<TreeLinkNode*> levels;

		int level = 0;
		connect(root, levels, level);
    }

	void connect(TreeLinkNode* root, vector<TreeLinkNode*>& levels, int level) {
		if (NULL == root) {
			return;
		} else {
			if (levels.size() <= level) {
				levels.push_back(root);
			} else {
				root->next = levels[level];
				levels[level] = root;
			}

			connect(root->right, levels, level + 1);
			connect(root->left, levels, level + 1);
		}
	}
};

void composeTree(TreeLinkNode* root, const vector<int>& nodes, int& index) {
	if (nodes[index] != -999998) {
		root->left = new TreeLinkNode(nodes[index]);
		++ index;
		composeTree(root->left, nodes, index);
	} else {
		++ index;
	}

	if (nodes[index] != -999998) {
		root->right = new TreeLinkNode(nodes[index]);
		++ index;
		composeTree(root->right, nodes, index);
	} else {
		++ index;
	}
}


TreeLinkNode* composeTree(const vector<int>& nodes) {
	if (nodes.size() == 0) {
		return NULL;
	}

	TreeLinkNode* root = new TreeLinkNode(nodes[0]);
	int index = 1;

	composeTree(root, nodes, index);

	return root;
}

void printNode(TreeLinkNode* root) {
	if (NULL == root) {
		return;
	}

	if (root->next == NULL) {
		cout << root->val << " NULL" << endl;
	} else {
		cout << root->val << " " << root->next->val << endl;
	}
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

	TreeLinkNode* root = composeTree(nodes);

	Solution solution;
	solution.connect(root);

	printNode(root);

	return 0;
}
