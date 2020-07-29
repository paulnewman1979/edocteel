#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i;
        vector<int> minCost(cost.size() + 1, 0);
        minCost[0] = 0;
        minCost[1] = 0;
        index = 0;
        for (i = 2; i <= cost.size(); ++i) {
            minCost[index] = min(minCost[1 - index] + cost[i - 1], minCost[index] + cost[i - 2]);
            index = 1 - index;
        }
        return minCost[1 - index];
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.minCostClimbingStairs(valueVec);

    // output
    Output(ret);

    return 0;
}
