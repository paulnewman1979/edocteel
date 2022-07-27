#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ret = 0, i, size = nums.size();
        long long int sum = 0;
        set<long long int> sums;
        set<long long int>::const_iterator iter;
        unordered_map<long long int, int> sumCount;
        sums.insert(0);
        sumCount[0] = 1;
        for (i = 0; i < size; ++i) {
            sum += nums[i];
            iter = sums.lower_bound(sum - upper);
            while ((iter != sums.end()) &&
                        ((*iter) <= sum - lower)) {
                ret += sumCount[(*iter)];
                ++iter;
            }
            sumCount[sum]++;
            sums.insert(sum);
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int lower, upper;
    vector<int> valueVec;
    Input(lower);
    Input(upper);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.countRangeSum(valueVec, lower, upper);

    // output
    Output(ret);

    return 0;
}
