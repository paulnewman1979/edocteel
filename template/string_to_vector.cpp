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
    vector<string> ambiguousCoordinates(string S) {
        vector<string> results;
        return results;
    }
};

int main(int argc, char* argv[])
{
    string S;
    getline(cin, S);

    Solution solution;
    vector<string> result = solution.ambiguousCoordinates(S);
    for (auto i : result) {
        cout << i << endl;
    }

    return 0;
}
