#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (sum % k != 0) return false;
        int average = sum / k;

        sort(nums.begin(), nums.end(), greater<>());
        if (nums[0] > average) return false;

        vector<int> sums(k, 0);
        vector<int> pos(nums.size(), -1);
        pos[0] = 0;
        sums[0] = nums[0];
        int i = 1;
        while ((i < nums.size()) && (i > 0)) {
            pos[i]++;
            while ((pos[i] < k) && (sums[pos[i]] + nums[i] > average)) pos[i]++;
            if (pos[i] < k) {
                sums[pos[i]] += nums[i];
                //cout << "add: " << i << " nums[i]=" << nums[i] 
                //    << " kindex=" << pos[i] << " sum[kindex]=" << sums[pos[i]] << endl;
                ++i;
            } else {
                pos[i] = -1;
                --i;
                sums[pos[i]] -= nums[i];
                //cout << "del: " << i << " nums[i]=" << nums[i]
                //    << " kindex=" << pos[i] << " sum[kindex]=" << sums[pos[i]] << endl;
            }
        }
        return (i == nums.size());
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
    bool ret = solution.canPartitionKSubsets(valueVec, k);

    // output
    Output(ret);

    return 0;
}
