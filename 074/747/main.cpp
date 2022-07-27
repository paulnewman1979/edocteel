#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (1 == nums.size()) return 0;

        int max1, max2, i, maxIndex;
        if (nums[0] > nums[1]) {
            max1 = nums[0];
            max2 = nums[1];
            maxIndex = 0;
        } else {
            max1 = nums[1];
            max2 = nums[0];
            maxIndex = 1;
        }

        for (i = 2; i < nums.size(); ++i) {
            if (nums[i] > max1) {
                maxIndex = i;
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] > max2) {
                max2 = nums[i];
            }
        }
        return (max1 >= max2 * 2) ? maxIndex : -1;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.dominantIndex(valueVec);

    // output
    Output(ret);

    return 0;
}
