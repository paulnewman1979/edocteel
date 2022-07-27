#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size(), i, j;
        vector<pair<int, int>> count(size, pair(0, 0));
        vector<int> ret;

        sort(nums.begin(), nums.end());
        count[size - 1] = pair(1, size - 1);
        for (i = size - 2; i >= 0; --i) {
            count[i] = pair(1, i);
            for (j = i + 1; j < size; j++) {
                if ((nums[j] % nums[i] == 0) &&
                    (count[i].first < count[j].first + 1)) {
                    count[i] = pair(count[j].first + 1, j);
                }
            }
        }
        j = 1;
        for (i = 0; i < size; ++i) {
            if (count[i].first > j) j = count[i].first;
        }
        for (i = 0; i < size; ++i) {
            if (count[i].first == j) {
                j = i;
                while (j != count[j].second) {
                    ret.push_back(nums[j]);
                    j = count[j].second;
                }
                ret.push_back(nums[j]);
                break;
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
    vector<int> ret = solution.largestDivisibleSubset(valueVec);

    // output
    Output(ret);

    return 0;
}
