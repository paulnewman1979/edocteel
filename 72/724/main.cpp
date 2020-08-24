#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, i, j;
        for (i = 0; i < nums.size(); i++) sum += nums[i];
        j = 0;
        for (i = 0; i < nums.size(); i++) {
            if (j == sum - j - nums[i]) return i;
            j += nums[i];
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.pivotIndex(valueVec);

    // output
    Output(ret);

    return 0;
}
