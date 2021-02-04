#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        stringstream ss;
        int size = nums.size();
        if (1 == size) {
            ss << nums[0];
        } else if (2 == size) {
            ss << nums[0] << "/" << nums[1];
        } else {
            ss << nums[0] << "/(" << nums[1];
            for (int i = 2; i < size; ++i) {
                ss << "/" << nums[i];
            }
            ss << ")";
        }
        return ss.str();
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    string ret = solution.optimalDivision(valueVec);

    // output
    Output(ret);

    return 0;
}
