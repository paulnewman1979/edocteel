#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int i, j, size = nums.size(), ret;
        vector<pair<int, int>> maxLengthCount(size, pair<int,int>(1, 1));
        for (i = 1; i < size; ++i) {
            for (j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (maxLengthCount[j].first + 1 > maxLengthCount[i].first) {
                        maxLengthCount[i].first = maxLengthCount[j].first + 1;
                        maxLengthCount[i].second = maxLengthCount[j].second;
                    } else if (maxLengthCount[j].first + 1 == maxLengthCount[i].first) {
                        maxLengthCount[i].second += maxLengthCount[j].second;
                    }
                }
            }
        }
        ret = 0;
        j = 0;
        for (i = 1; i < size; ++i) {
            if (maxLengthCount[i].first > maxLengthCount[j].first) {
                j = i;
                ret = maxLengthCount[i].second;
            } else if (maxLengthCount[i].first == maxLengthCount[j].first) {
                ret += maxLengthCount[i].second;
            }
        }
        return (maxLengthCount[j].first == 1) ? size : ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.findNumberOfLIS(valueVec);

    // output
    Output(ret);

    return 0;
}
