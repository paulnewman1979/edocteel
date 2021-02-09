#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        vector<vector<int>> powerGroup(33);
        vector<vector<int>> negPowerGroup(32);
        vector<int>::iterator iter;
        static const int posBar = (1<<30);
        static const int negBar = -(1<<30);
        int ret = 0, i, j, k, size = nums.size(), posCount = 0;
        for (i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                ++posCount;
                for (j = 1; j < 33; ++j) ret += powerGroup[j].size();
                powerGroup[0].push_back(nums[i]);
            } else if (nums[i] > 0) {
                ++posCount;
                j = nums[i] - 1; k = 1; while (j > 0) { ++k; j=j>>1;}
                for (j = k + 2; j < 33; ++j) ret += powerGroup[j].size();

                if (nums[i] < posBar) {
                    iter = upper_bound(powerGroup[k+1].begin(), powerGroup[k+1].end(), nums[i] * 2);
                    ret += powerGroup[k+1].size() - (iter - powerGroup[k+1].begin());
                }

                iter = upper_bound(powerGroup[k].begin(), powerGroup[k].end(), nums[i]);
                powerGroup[k].insert(iter, nums[i]);
            } else {
                ret += posCount;
                j = -(nums[i] + 1); k = 0; while (j > 0) { ++k; j=j>>1;}
                for (j = k; j >= 0; --j) ret += negPowerGroup[j].size();

                if (nums[i] >= negBar) {
                    iter = upper_bound(negPowerGroup[k+1].begin(), negPowerGroup[k+1].end(), nums[i] * 2);
                    ret += negPowerGroup[k+1].size() - (iter - negPowerGroup[k+1].begin());
                }

                iter = upper_bound(negPowerGroup[k].begin(), negPowerGroup[k].end(), nums[i]);
                negPowerGroup[k].insert(iter, nums[i]);
            }
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
    int ret = solution.reversePairs(valueVec);

    // output
    Output(ret);

    return 0;
}
