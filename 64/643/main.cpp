#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i, j;
        double maxValue = 0.0, curValue = 0.0;
        for (i = 0; i < k; ++i) {
            maxValue += nums[i];
        }
        curValue = maxValue;
        j = 0;
        for (; i < nums.size(); ++i, ++j) {
            curValue += nums[i] - nums[j];
            if (curValue > maxValue) maxValue = curValue;
        }
        return maxValue / k;
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
    double ret = solution.findMaxAverage(valueVec, k);

    // output
    Output(ret);

    return 0;
}
