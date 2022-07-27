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
    int maxPathSum(TreeNode* root) {
		if (NULL == root) {
			return 0;
		}

		int maxSum = -0x8000000;
		maxPathSum(root, maxSum);

		return maxSum;
    }

	int maxPathSum(TreeNode* root, int& maxSum) {
		int maxLeft = 0;
		int maxRight = 0;
		if (NULL != root->left) {
			maxLeft = maxPathSum(root->left, maxSum);
			if (maxLeft < 0) {
				maxLeft = 0;
			}
		}
		if (NULL != root->right) {
			maxRight = maxPathSum(root->right, maxSum);
			if (maxRight < 0) {
				maxRight = 0;
			}
		}
		if (maxLeft + maxRight + root->val > maxSum) {
			maxSum = maxLeft + maxRight + root->val;
		}

		return ((maxLeft>maxRight)?maxLeft:maxRight) + root->val;
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
	cout << solution.maxPathSum(root) << endl;

    return 0;
}
