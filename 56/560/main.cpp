#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i, ret, sum;
        unordered_map<int, int> sumPos;
        unordered_map<int, int>::const_iterator iter; 
        sum = 0;
        sumPos[0] = 1;
        ret = 0;
        for (i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            iter = sumPos.find(sum - k);
            if (iter != sumPos.end()) {
                ret += iter->second;
            }
            sumPos[sum]++;
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    int value;
    Input(value);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.subarraySum(valueVec, value);

    // output
    Output(ret);

    return 0;
}
