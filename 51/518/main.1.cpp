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
        int i, j, k;
        vector<int> comb(amount + 1, 0);
        comb[0] = 1;
        for (i = 0; i < coins.size(); ++i) {
            for (j = amount; j > 0; --j) {
                for (k = j - coins[i]; k >= 0; k -= coins[i]) {
                    comb[j] += comb[k];
                }
            }
        }
        return comb[amount];
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
