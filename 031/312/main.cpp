#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        _n = nums.size();
        if (_n == 1) return nums[0];
        int i = 0;
        _dp.resize(_n);
        for (i = 0; i < _n; ++i) _dp[i].resize(_n, -1);

        _dp[0][0] = nums[0] * nums[1];
        _dp[_n - 1][_n - 1] = nums[_n - 2] * nums[_n - 1];
        for (i = 1; i < _n - 1; ++i) {
            _dp[i][i] = nums[i - 1] * nums[i] * nums[i + 1];
        }
        maxCoins(nums, 0, _n - 1);
        return _dp[0][_n - 1];
    }

private:
    int maxCoins(vector<int>& nums,
            int start,
            int end) {
        int lp, curCoin;

        if (_dp[start + 1][end] == -1) {
            _dp[start][end] = maxCoins(nums, start + 1, end) + calLast(nums, start, end, start);
        } else {
            _dp[start][end] = _dp[start + 1][end] + calLast(nums, start, end, start);
        }

        if (_dp[start][end - 1] == -1) {
            curCoin = maxCoins(nums, start, end - 1) + calLast(nums, start, end, end);
        } else {
            curCoin = _dp[start][end - 1] + calLast(nums, start, end, end);
        }
        if (curCoin > _dp[start][end]) {
            _dp[start][end] = curCoin;
        }

        for (lp = start + 1; lp < end; ++lp) {
            curCoin = calLast(nums, start, end, lp);
            curCoin += (_dp[start][lp - 1] == -1) ? maxCoins(nums, start, lp - 1) : _dp[start][lp - 1];
            curCoin += (_dp[lp + 1][end] == -1) ? maxCoins(nums, lp + 1, end) : _dp[lp + 1][end];
            if (curCoin > _dp[start][end]) _dp[start][end] = curCoin;
        }
        return _dp[start][end];
    }

private:
    inline int calLast(vector<int>& nums, int start, int end, int lp) {
        if (start == 0) {
            return (end == _n - 1) ? nums[lp] : nums[lp] * nums[end + 1];
        } else if (end == _n - 1) {
            return nums[start - 1] * nums[lp];
        } else {
            return nums[start - 1] * nums[lp] * nums[end + 1];
        }
    }

private:
    int _n;
    vector<vector<int>> _dp;
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.maxCoins(valueVec);

    // output
    Output(ret);

    return 0;
}
