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
    int findPairs(vector<int>& nums, int k) {
        int ret = 0, i;
        unordered_map<int, int> numMap;
        unordered_map<int, int>::const_iterator iter1, iter2;
        for (i = 0; i < nums.size(); ++i) {
            numMap[nums[i]]++;
        }

        if (k == 0) {
            iter1 = numMap.begin();
            while (iter1 != numMap.end()) {
                if (iter1->second > 1) {
                    ++ret;
                }
                ++iter1;
            }
        } else {
            iter1 = numMap.begin();
            while (iter1 != numMap.end()) {
                iter2 = numMap.find(iter1->first + k);
                if (iter2 != numMap.end()) {
                    ++ret;
                }
                ++iter1;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    int k;
    Input(k);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.findPairs(valueVec, k);

    // output
    Output(ret);

    return 0;
}
