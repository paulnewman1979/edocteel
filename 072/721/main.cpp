#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> results;
        unordered_map<string, int> emailToAccount;
        unordered_map<string, int>::iterator iter;
        int size = accounts.size();
        int i, j, root1, root2;
        vector<int> rootAccount(size, 0);
        for (i = 0; i < size; ++i) {
            rootAccount[i] = i;
        }
        for (i = 0; i < size; ++i) {
            root1 = i;
            for (j = 1; j < accounts[i].size(); ++j) {
                iter = emailToAccount.find(accounts[i][j]);
                if (iter == emailToAccount.end()) {
                    emailToAccount[accounts[i][j]] = root1;
                } else {
                    root2 = iter->second;
                    while (rootAccount[root2] != root2) root2 = rootAccount[root2];
                    if (root1 < root2) {
                        rootAccount[root2] = root1;
                    } else {
                        rootAccount[root1] = root2;
                        root1 = root2;
                    }
                }
            }
        }

        unordered_map<int, int> rootToNewRoot;
        int count = 0;
        for (i = 0; i < size; ++i) {
            if (i == rootAccount[i]) {
                rootToNewRoot[i] = count;
                ++count;
                results.push_back(vector<string>(1, accounts[i][0]));
            } 
        }

        for (i = 0; i < size; ++i) {
            for (j = 1; j < accounts[i].size(); ++j) {
                root1 = emailToAccount[accounts[i][j]];
                if (root1 != -1) {
                    emailToAccount[accounts[i][j]] = -1;
                    while (root1 != rootAccount[root1]) root1 = rootAccount[root1];
                    results[rootToNewRoot[root1]].push_back(accounts[i][j]);
                }
            }
        }

        for (i = 0; i < count; ++i) {
            sort(results[i].begin(), results[i].end());
        }

        return results;
    }
};

int main(int argc, char* argv[])
{
    // input
	vector<vector<string> > valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
	vector<vector<string> > results = solution.accountsMerge(valueGrid);

    // output
    Output(results);

    return 0;
}
