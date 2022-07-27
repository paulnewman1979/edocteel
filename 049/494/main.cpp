#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (1 == nums.size()) {
            if ((nums[0] == target) || (nums[0] == -target)) return 1; else return 0;
        }
        int n = nums.size(), i, ret = 0;
        unordered_map<int, int> tmp, start, end;
        unordered_map<int, int>::iterator iter, it;
        start[0] = 1;
        for (i = 0; i < n/2; ++i) {
            start.swap(tmp);
            start.clear();
            for (iter = tmp.begin(); iter != tmp.end(); ++iter) {
                start[iter->first + nums[i]] += iter->second;
                start[iter->first - nums[i]] += iter->second;
            }
        }

        end[target] = 1;
        for (i = n - 1; i >= n/2; --i) {
            end.swap(tmp);
            end.clear();
            for (iter = tmp.begin(); iter != tmp.end(); ++iter) {
                end[iter->first + nums[i]] += iter->second;
                end[iter->first - nums[i]] += iter->second;
            }
        }

        for (iter = start.begin(); iter != start.end(); ++iter) {
            it = end.find(iter->first);
            if (it != end.end()) ret += iter->second * it->second;
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int target;
    vector<int> valueVec;
    Input(target);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.findTargetSumWays(valueVec, target);

    // output
    Output(ret);

    return 0;
}
