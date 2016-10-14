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
    int sumNumbers(TreeNode* root) {
		if (NULL == root) {
			return 0;
		}

		int sumTotal = 0;
		sumNumbers(root, 0, sumTotal);

		return sumTotal;
    }

	void sumNumbers(TreeNode* root, int sum, int& sumTotal) {
		if (root->left == NULL) {
			if (root->right == NULL) {
				sumTotal += sum * 10 + root->val;
			} else {
				sumNumbers(root->right, sum * 10 + root->val, sumTotal);
			}
		} else if (root->right == NULL) {
			sumNumbers(root->left, sum * 10 + root->val, sumTotal);
		} else {
			sumNumbers(root->left, sum * 10 + root->val, sumTotal);
			sumNumbers(root->right, sum * 10 + root->val, sumTotal);
		}
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
	cout << solution.sumNumbers(root) << endl;

    return 0;
}
