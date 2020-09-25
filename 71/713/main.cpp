#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ret = 0, i = 0, j = 0, size = nums.size();
        long long int product = 1;
        for (i = 0; i < nums.size(); ++i) {
            while ((j < size) && (product < k)) {
                product *= nums[j];
                ++j;
            }
            ret += (product < k) ? (j - i) : ((j > i) ? (j - i - 1) : 0);
            product /= nums[i];
        }
        return ret;
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
    int ret = solution.numSubarrayProductLessThanK(valueVec, value);

    // output
    Output(ret);

    return 0;
}
