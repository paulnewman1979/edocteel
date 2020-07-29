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
        int i, size = cost.size() + 1;
        vector<int> minCost(size, 0);
        for (i = 2; i < size; ++i) {
            minCost[i] = min(minCost[i - 1] + cost[i - 1], minCost[i - 2] + cost[i - 2]);
        }
        return minCost[size - 1];
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
