#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ret = 0, i;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size(); i+=2) {
            ret += nums[i];
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.arrayPairSum(valueVec);

    // output
    Output(ret);

    return 0;
}
