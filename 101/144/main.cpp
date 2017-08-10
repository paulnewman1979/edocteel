#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <deque>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (NULL == root) {
            return result;
        }
        
        deque<TreeNode*> leftUndone;
        vector<TreeNode*> rightToDo;
        
        leftUndone.push_back(root);
        TreeNode* cur;
        while (leftUndone.size() > 0) {
            cur = leftUndone.front();
            leftUndone.pop_front();
            
            result.push_back(cur->val);
            if (cur->left != NULL) {
                leftUndone.push_back(cur->left);
            }
            if (cur->right != NULL) {
                rightToDo.push_back(cur->right);
            }
            
            if ((leftUndone.size() == 0) &&
                (rightToDo.size() > 0)) {
                cur = rightToDo.back();
                rightToDo.pop_back();
                leftUndone.push_back(cur);
            }
        }
        
        return result;
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
	vector<int> result = solution.preorderTraversal(root);

	for (n=0; n<result.size(); ++n) {
		cout << result[n] << endl;
	}
    return 0;
}



