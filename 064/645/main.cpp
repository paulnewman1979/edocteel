#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i;
        long long int sum1 = 0, sum2 = 0, expectedSum1 = 0, expectedSum2 = 0;
        for (i = 1; i <= nums.size(); ++i) {
            expectedSum1 += i;
            expectedSum2 += i * i;
            sum1 += nums[i - 1];
            sum2 += nums[i - 1] * nums[i - 1];
        }
        int a = ((sum2 - expectedSum2) / (sum1 - expectedSum1) + (sum1 - expectedSum1)) / 2;
        int b = a + expectedSum1 - sum1;
        return vector<int>({a, b});
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> words;
    Input(words);

    // solution
    Solution solution;
    vector<int> ret = solution.findErrorNums(words);

    // output
    Output(ret);

    return 0;
}
