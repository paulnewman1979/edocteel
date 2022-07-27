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
    int findMaxLength(vector<int>& nums) {
        int count = 0, maxLength = 0, i;
        unordered_map<int, int> countMap;
        unordered_map<int, int>::const_iterator iter;
        countMap[0] = 0;
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) ++count;
            else --count;
            iter = countMap.find(count);
            if (iter == countMap.end()) {
                countMap[count] = i + 1;
            } else if (i + 1 - iter->second > maxLength) {
                maxLength = i + 1 - iter->second;
            }
        }
        return maxLength;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.findMaxLength(valueVec);

    // output
    Output(ret);

    return 0;
}
