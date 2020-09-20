#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (0 == prices.size()) return 0;
        int sum = 0;
        int i = 1, max = prices[0], min = prices[0];
        for (; i < prices.size(); ++i) {
            if (prices[i] > max) {
                max = prices[i];
            } else if ((prices[i] <= max - fee) || (prices[i] <= min)) {
                if (max - min > fee) sum += max - min - fee;
                min = max = prices[i];
            }
        }
        if (max - min > fee) sum += max - min - fee;
        return sum;
    }
};

int main(int argc, char* argv[])
{
    // input
    int value;
    vector<int> valueVec;
    Input(value);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.maxProfit(valueVec, value);

    // output
    Output(ret);

    return 0;
}
