#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int distance = (target[0] > 0) ? target[0] : -target[0];
        distance += (target[1] > 0) ? target[1] : -target[1];
        for (int i = 0; i < ghosts.size(); ++i) {
            int newDistance = (ghosts[i][0] > target[0]) ? ghosts[i][0] - target[0] :
                target[0] - ghosts[i][0];
            newDistance += (ghosts[i][1] > target[1]) ? ghosts[i][1] - target[1] :
                target[1] - ghosts[i][1];
            if (newDistance <= distance) return false;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    vector<int> valueVec;
    Input(valueGrid);
    Input(valueVec);

    // solution
    Solution solution;
    bool ret = solution.escapeGhosts(valueGrid, valueVec);

    // output
    Output(ret);

    return 0;
}
