#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int i, j, index, prevIndex;
        vector<vector<int>> comb(2, vector(amount + 1, 0));
        comb[0][0] = 1;
        comb[1][0] = 1;
        index = 0;
        for (i = 0; i < coins.size(); ++i) {
            prevIndex = index;
            index = 1 - prevIndex;
            for (j = 1; j <= min(coins[i] - 1, amount); ++j) {
                comb[index][j] = comb[prevIndex][j];
            }
            for (j = coins[i]; j <= amount; ++j) {
                comb[index][j] = comb[index][j - coins[i]] + comb[prevIndex][j];
            }
        }
        return comb[index][amount];
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
    int ret = solution.change(value, valueVec);

    // output
    Output(ret);

    return 0;
}
