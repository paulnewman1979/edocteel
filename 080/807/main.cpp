#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<int> iMax(grid.size(), 0);
        vector<int> jMax(grid[0].size(), 0);
        int ret = 0, i, j;;
        for (i = 0; i < grid.size(); ++i) {
            for (j = 0; j <grid[i].size(); ++j) {
                if (grid[i][j] > iMax[i]) iMax[i] = grid[i][j];
                if (grid[i][j] > jMax[j]) jMax[j] = grid[i][j];
            }
        }
        for (i = 0; i < grid.size(); ++i) {
            for (j = 0; j < grid[i].size(); ++j) {
                ret += min(iMax[i], jMax[j]) - grid[i][j];
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.maxIncreaseKeepingSkyline(valueGrid);

    // output
    Output(ret);

    return 0;
}
