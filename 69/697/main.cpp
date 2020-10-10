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
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> numMap;
        unordered_map<int, vector<int>>::iterator iter;
        for (int i = 0; i < nums.size(); ++i) {
            iter = numMap.find(nums[i]);
            if (iter == numMap.end()) {
                numMap[nums[i]] = vector<int>{1, i, i};
            } else {
                iter->second[0]++;
                if (iter->second[2] < i) iter->second[2] = i;
            }
        }
        int maxFreq = 0;
        int minLength = nums.size() - 1;
        for (iter = numMap.begin(); iter != numMap.end(); ++iter) {
            if (maxFreq < iter->second[0]) {
                maxFreq = iter->second[0];
                minLength = iter->second[2] - iter->second[1] + 1;
            } else if ((maxFreq == iter->second[0]) &&
                    (iter->second[2] - iter->second[1] < minLength)) {
                minLength = iter->second[2] - iter->second[1] + 1;
            }
        }
        return minLength;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.findShortestSubArray(valueVec);

    // output
    Output(ret);

    return 0;
}
