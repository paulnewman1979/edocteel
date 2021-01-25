#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

static const unsigned long long int MOD = 1000000007ULL;

class Solution {
public:
    int kInversePairs(int n, int k) {
        if (0 == k) return 1;
        if (1 == n) return 0;
        vector<vector<unsigned long long int>> reverse(2, vector<unsigned long long int>(k + 1, 0));
        int i, j, index = 0, prevIndex;
        reverse[0][0] = 1;  // 2
        reverse[0][1] = 1;  // 2
        reverse[1][0] = 1;
        for (i = 3; i <= n; ++i) {
            prevIndex = index;
            index = 1 - prevIndex;
            for (j = 1; j <= min(k, i * (i - 1) / 2); ++j) {
                reverse[index][j] = reverse[prevIndex][j] + reverse[index][j - 1];
                if (j >= i) {
                    reverse[index][j] += MOD - reverse[prevIndex][j - i];
                }
                reverse[index][j] %= MOD;
            }
        }
		return reverse[index][k];
    }
};

int main(int argc, char* argv[])
{
    // input
    int sx, sy;
    Input(sx);
    Input(sy);

    // solution
    Solution solution;
    int ret = solution.kInversePairs(sx, sy);

    // output
    Output(ret);

    return 0;
}
