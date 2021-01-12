#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int max = 1, tmp = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++tmp;
                //cout << tmp << " " << nums[i] << " > " << nums[i - 1] << endl;
            } else {
                if (tmp > max) {
                    max = tmp;
                }
                tmp = 1;
            }
        }
        if (tmp > max) {
            max = tmp;
        }
        return max;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.findLengthOfLCIS(valueVec);

    // output
    Output(ret);

    return 0;
}
