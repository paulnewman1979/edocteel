#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if (wall.size() == 1) return (wall[0].size() == 1) ? 1 : 0;
        int maxCount = 0, i, j, k;
        unordered_map<int, int> count;
        for (i = 0; i < wall.size(); ++i) {
            k = 0;
            for (j = 0; j < wall[i].size() - 1; ++j) {
                k += wall[i][j];
                count[k]++;
                if (count[k] > maxCount) maxCount = count[k];
            }
        }
        return wall.size() - maxCount;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.leastBricks(valueGrid);

    // output
    Output(ret);

    return 0;
}
