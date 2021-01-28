#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.size() == 0) return vector<int>();
        int i, max = nums[0], maxIndex = 0, j, size = nums.size();
        vector<int> ret(size, -1);
        for (i = 0; i < size; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
        }

        i = maxIndex;
        for (i = maxIndex + 1; i < size; ++i) {
            for (j = i + 1; j < size; ++j) {
                if (nums[j] > nums[i]) break;
            }
            if (j < size) ret[i] = nums[j];
            else {
                for (j = 0; j < i; ++j) {
                    if (nums[j] > nums[i]) break;
                }
                ret[i] = (j < i) ? nums[j] : -1;
            }
        }
        for (i = 0; i < maxIndex; ++i) {
            for (j = i + 1; j < size; ++j) {
                if (nums[j] > nums[i]) break;
            }
            if (j < size) ret[i] = nums[j];
            else {
                for (j = 0; j < i; ++j) {
                    if (nums[j] > nums[i]) break;
                }
                ret[i] = (j < i) ? nums[j] : -1;
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
    vector<int> ret = solution.nextGreaterElements(valueVec);

    // output
    Output(ret);

    return 0;
}
