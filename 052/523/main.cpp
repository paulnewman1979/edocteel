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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i;
        if (0 == k) {
            for (i = 0; i < nums.size() - 1; ++i) {
                if ((nums[i] == 0) && (nums[i + 1] == 0)) return true;
            }
            return false;
        } else {
            int modSum = 0, i;
            if (k < 0) k = -k;
            unordered_map<int, int> modIndexMap;
            unordered_map<int, int>::iterator iter;
            modIndexMap[0] = 0;
            for (i = 0; i < nums.size(); ++i) {
                modSum = (modSum + nums[i]) % k;
                iter = modIndexMap.find(modSum);
                if (iter == modIndexMap.end()) {
                    modIndexMap[modSum] = i + 1;
                } else if (i > iter->second) {
                    return true;
                }
            }
        }
        return false;
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
    bool ret = solution.checkSubarraySum(valueVec, k);

    // output
    Output(ret);

    return 0;
}
