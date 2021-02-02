#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, k;
        while (i + 2 <= j) {
            k = (i + j) / 2;
            if (nums[k] == nums[k + 1]) {
                if (k % 2 == 0) {
                    i = k + 2;
                } else {
                    j = k - 1;
                }
            } else if (nums[k] == nums[k - 1]) {
                if (k % 2 == 0) {
                    j = k - 2;
                } else {
                    i = k + 1;
                }
            } else{
                return nums[k];
            }
        }
        return nums[i];
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.singleNonDuplicate(valueVec);

    // output
    Output(ret);

    return 0;
}
