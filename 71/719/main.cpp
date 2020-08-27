#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums.back() - nums.front();
        int i, j, m, cnt;
        while (l <= r) {
            cnt = 0;
            j = 0;
            m = (l + r) / 2;
            for (i = 0; i < n; ++i) {
                while ((j < n) && (nums[j] - nums[i] <= r)) ++j;
                cnt += j - i - 1;
            }
            (cnt >= k) ? r = m - 1 : l = m + 1;
        }
        return l;
    }
};

int main(int argc, char* argv[])
{
    // input
    int k;
    vector<int> valueVec;
    Input(k);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.smallestDistancePair(valueVec, k);

    // output
    Output(ret);

    return 0;
}
