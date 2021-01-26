#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3) return nums[0] * nums[1] * nums[2];
        int i, j, cur;
        vector<int> record(10, 0);
        bool hasZero = false;
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                cur = nums[i];
                for (j = 0; j < 3; ++j) if (cur > record[j]) swap(cur, record[j]);
                cur = nums[i];
                for (j = 3; j < 5; ++j) if ((record[j] == 0) || (cur < record[j])) swap(cur, record[j]);
            } else if (nums[i] < 0) {
                cur = nums[i];
                for (j = 5; j < 8; ++j) if ((record[j] == 0) || (cur > record[j])) swap(cur, record[j]);
                cur = nums[i];
                for (j = 8; j < 10; ++j) if (cur < record[j]) swap(cur, record[j]);
            } else {
                hasZero = true;
            }
        }

        int ret = 0;
        long long int comp = (long long int)record[0] * record[1] * record[2];
        if (comp > ret) ret = comp;
        comp = (long long int)record[0] * record[8] * record[9];
        if (comp > ret) ret = comp;
        if (ret > 0) return ret;
        if (hasZero) return 0;
        ret = record[5] * record[6] * record[7];
        comp = record[3] * record[4] * record[5];
        if ((comp < 0) && (comp > ret)) ret = comp;
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
    int ret = solution.maximumProduct(valueVec);

    // output
    Output(ret);

    return 0;
}
