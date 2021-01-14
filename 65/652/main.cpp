#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

typedef BaseTreeNode<int> TreeNode;
typedef unordered_map<int, vector<pair<int, TreeNode*>>> ValueMap;

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ret;
        if (root) {
            getValueAndKidNum(root);

            ValueMap::iterator iter = groupByValue.begin();
            int i, j;
            while (iter != groupByValue.end()) {
                vector<pair<int, TreeNode*>>& nodes = iter->second;
                for (i = 0; i < nodes.size(); ++i) {
                    if (nodes[i].first == -1) continue;
                    bool isFirst = true;
                    for (j = i + 1; j < nodes.size(); ++j) {
                        if (nodes[j].first == -1) continue;
                        if (nodes[i].first == nodes[j].first) {
                            if (validSame(nodes[i].second, nodes[j].second)) {
                                if (isFirst) {
                                    ret.push_back(nodes[i].second);
                                    isFirst = false;
                                }
                                nodes[j].first = -1;
                            }
                        }
                    }
                }
                ++iter;
            }
        }
        return ret;
    }

private:
    int getValueAndKidNum(TreeNode* root) {
        int kidNum = 0;
        if (root->left) {
            kidNum += getValueAndKidNum(root->left);
        }
        if (root->right) {
            kidNum += getValueAndKidNum(root->right);
        }
        groupByValue[root->val].push_back(make_pair(kidNum, root));
        return kidNum + 1;
    }

    bool validSame(TreeNode* n1, TreeNode* n2) {
        if (n1 == NULL) {
            if (n2 == NULL) return true;
            else return false;
        }
        else if (n2 == NULL) return false;
        else if (n1->val != n2->val) return false;
        else return (validSame(n1->left, n2->left) && validSame(n1->right, n2->right));
    }
        
private:
    ValueMap groupByValue;
};

int main(int argc, char* argv[])
{
    // input
    TreeNode* root;
    Input(root);

    // solution
    Solution solution;
    vector<TreeNode*> ret = solution.findDuplicateSubtrees(root);

    // output 2
    Output(ret);

    return 0;
}
