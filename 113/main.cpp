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
    vector< vector<int> > pathSum(TreeNode* root, int sum) {
		vector< vector<int> > paths;
		vector<int> path;

		if (NULL == root) {
			return paths;
		}
		pathSum(root, sum, 0, path, paths);

		return paths;
    }

	void pathSum(TreeNode* root, int sum, int curSum, vector<int>& path, vector< vector<int> >& paths) {
		if (root->left == NULL) {
			if (root->right == NULL) {
				if (sum == curSum + root->val) {
					path.push_back(root->val);
					paths.push_back(path);
					path.pop_back();
				}
			} else {
				path.push_back(root->val);
				pathSum(root->right, sum, curSum + root->val, path, paths);
				path.pop_back();
			}
		} else if (root->right == NULL) {
			path.push_back(root->val);
			pathSum(root->left, sum, curSum + root->val, path, paths);
			path.pop_back();
		} else {
			path.push_back(root->val);
			pathSum(root->left, sum, curSum + root->val, path, paths);
			pathSum(root->right, sum, curSum + root->val, path, paths);
			path.pop_back();
		}
	}
};

int main(int argc, char* argv[]) {
	TreeNode* root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int sum = 22;
	Solution solution;
	vector< vector<int> > results = solution.pathSum(root, sum);
	for (int i=0; i<results.size(); ++i) {
		for (int j=0; j<results[i].size(); ++j) {
			cout << results[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
