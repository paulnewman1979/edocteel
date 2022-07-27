#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i, j, k, min, max;
        i = 0;
        while ((i < nums.size() - 1) && (nums[i] <= nums[i + 1])) {
            ++i;
        }
        if (i == nums.size() - 1) return 0;

        j = nums.size() - 1;
        while ((j > 0) && (nums[j - 1] <= nums[j])) {
            --j;
        }

        min = nums[i];
        max = nums[i];
        for (k = i; k <= j; ++k) {
            if (nums[k] < min) min = nums[k];
            if (nums[k] > max) max = nums[k];
        }
        while ((i >= 0) && (nums[i] > min)) --i;
        ++i;
        while ((j < nums.size()) && (nums[j] < max)) ++j;
        return j - i;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.findUnsortedSubarray(valueVec);

    // output
    Output(ret);

    return 0;
}
