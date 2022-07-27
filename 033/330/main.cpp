#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ret = 0, i;
        int rangeMax = 0;
        for (i = 0; i < nums.size(); ++i) {
            while ((rangeMax < n) &&
                    (nums[i] > rangeMax + 1)) {
                ++ret;
                rangeMax = (rangeMax<<1) + 1;
            }
            if (rangeMax >= n - nums[i]) {
                return ret;
            } else {
                rangeMax += nums[i];
            }
        }

        while (rangeMax < n) {
            ++ret;
            if (rangeMax >= n - rangeMax - 1) {
                return ret;
            } else {
                rangeMax = (rangeMax<<1) + 1;
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    int n;
    Input(n);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.minPatches(valueVec, n);

    // output
    Output(ret);

    return 0;
}
