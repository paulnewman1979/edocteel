#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <set>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ret = 0;
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int i, j, k;
        vector<vector<int>> group(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        int curGroup = 0;
        for (i = 0; i < grid.size(); ++i) {
            for (j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    int root1 = INT_MAX, root2 = INT_MAX;
                    if ((i > 0) && (grid[i - 1][j] == 1)) {
                        root1 = findRoot(group[i - 1][j]);
                    }
                    if ((j > 0) && grid[i][j - 1] == 1) {
                        root2 = findRoot(group[i][j - 1]);
                    }
                    if (root1 < root2) {
                        group[i][j] = root1;
                        root[root1].second++;
                        if (root2 != INT_MAX) {
                            root[root2].first = root1;
                        }
                    } else if (root2 < root1) {
                        group[i][j] = root2;
                        root[root2].second++;
                        if (root1 != INT_MAX) {
                            root[root1].first = root2;
                        }
                    } else if (root1 == INT_MAX) {
                        group[i][j] = curGroup;
                        root[curGroup] = make_pair(curGroup, 1);
                        ++curGroup;
                    } else {
                        group[i][j] = root[root1].first;
                        root[root1].second++;
                    }
                }
            }
        }

        unordered_map<int, pair<int, int>>::const_iterator iter = root.begin();
        while (iter != root.end()) {
            i = findRoot(iter->first);
            if (i != iter->first) {
                root[i].second += iter->second.second;
            }
            ++iter;
        }

        for (i = 0; i < grid.size(); ++i) {
            for (j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    int sum = 1;
                    set<int> rootSet;
                    rootSet.clear();
                    if ((i > 0) && (group[i - 1][j] != INT_MAX)) {
                        k = findRoot(group[i - 1][j]);
                        rootSet.insert(k);
                        sum += root[k].second;
                    }
                    if ((i < grid.size() - 1) && (group[i + 1][j] != INT_MAX)) {
                        k = findRoot(group[i + 1][j]);
                        if (rootSet.find(k) == rootSet.end()) {
                            rootSet.insert(k);
                            sum += root[k].second;
                        }
                    }
                    if ((j > 0) && (group[i][j - 1] != INT_MAX)) {
                        k = findRoot(group[i][j - 1]);
                        if (rootSet.find(k) == rootSet.end()) {
                            rootSet.insert(k);
                            sum += root[k].second;
                        }
                    }
                    if ((j < grid[i].size() - 1) && group[i][j + 1] != INT_MAX) {
                        k = findRoot(group[i][j + 1]);
                        if (rootSet.find(k) == rootSet.end()) {
                            rootSet.insert(k);
                            sum += root[k].second;
                        }
                    }
                    if (sum > ret) {
                        ret = sum;
                    }
                }
            }
        }

        if (ret == 0) {
            if (grid[0][0] == 1) {
                ret = grid.size() * grid[0].size();
            } else {
                ret = 1;
            }
        }

        return ret;
    }

private:
    int findRoot(int i) {
        while (root[i].first != i) {
            i = root[i].first;
        }
        return i;
    }

    unordered_map<int, pair<int, int>> root;
};

int main(int argc, char* argv[])
{
    // input
    vector< vector<int> > valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.largestIsland(valueGrid);

    // output
    Output(ret);

    return 0;
}
