#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int size = nums.size(), i;
        vector<vector<int>> dp(size, vector<int>(m + 1, -1));
        dp[0][1] = nums[0];
        for (i = 1; i < size; ++i) {
            dp[i][1] = dp[i - 1][1] + nums[i];
        }
        if (1 != m) {
            splitArray(nums, m, size - 1, dp);
        }
        return dp[size - 1][m];
    }

private:
    void splitArray(vector<int>&nums,
            int m,
            int end,
            vector<vector<int>>& dp) {
        int k = end, sum = 0;
        if (dp[end][m - 1] == -1) {
            splitArray(nums, m - 1, end, dp);
        }
        dp[end][m] = dp[end][m - 1];
        while (k > 0) {
            sum += nums[k];
            if (dp[k - 1][m - 1] == -1) {
                splitArray(nums, m - 1, k - 1, dp);
            }
            if (sum >= dp[k - 1][m - 1]) {
                break;
            }
            --k;
        }
        if (k == 0) {
            if (dp[end][m] > nums[0]) dp[end][m] = nums[0];
        } else {
            if (dp[end][m] > sum) dp[end][m] = sum;
            if (dp[end][m] > dp[k][m - 1]) dp[end][m] = dp[k][m - 1];
        }
    }
};

int main(int argc, char* argv[])
{
    // input
    int m;
    vector<int> valueVec;
    Input(m);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.splitArray(valueVec, m);

    // output
    Output(ret);

    return 0;
}
