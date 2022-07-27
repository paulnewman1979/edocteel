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
        int count = 50000, maxLength = 0, i;
        vector<int> countPos(100001, -1);
        countPos[50000] = 0;
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) ++count;
            else --count;
            if (countPos[count] == -1) {
                countPos[count] = i + 1;
            } else if (i + 1 - countPos[count] > maxLength) {
                maxLength = i + 1 - countPos[count];
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
