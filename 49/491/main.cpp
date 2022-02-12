#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

struct Node {
    Node(int value) { _value = value; }
    int _value;
    vector<Node*> _nexts;
};

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<Node*> leaves, todo;
        Node* root = new Node(-200);
        leaves.push_back(root);
        for (int i = 0; i < nums.size(); ++i) {
            todo.clear();
            for (auto& leave : leaves) {
                if (leave->_value <= nums[i]) {
                    bool found = false;
                    if (leave->_nexts.size() > 0) {
                        for (auto& next : leave->_nexts) {
                            if (next->_value == nums[i]) {
                                found = true;
                            }
                        }
                    }
                    if (!found) {
                        leave->_nexts.push_back(new Node(nums[i]));
                        todo.push_back(leave->_nexts.back());
                    }
                }
            }
            leaves.insert(leaves.end(), todo.begin(), todo.end());
        }

        vector<int> cur;
        traverseTree(root, 0, result, cur);
        return result;
    }

private:
    void traverseTree(const Node* root, const int depth, vector<vector<int>>& result,vector<int>& cur) {
        for (auto& next : root->_nexts) {
            cur.push_back(next->_value);
            if (depth >= 1) {
                result.push_back(cur);
            }
            traverseTree(next, depth + 1, result, cur);
            cur.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> nums;
    Input(nums);

    // solution
    Solution solution;
    vector<vector<int>> ret = solution.findSubsequences(nums);

    // output
    Output(ret);

    return 0;
}
