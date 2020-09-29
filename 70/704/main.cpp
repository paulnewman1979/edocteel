#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if ((target < nums[0]) || (target > nums[size -1])) return -1;
        if (target == nums[0]) return 0;
        if (target == nums[size - 1]) return size - 1;

        int first = 0, last = size - 1, middle;
        while (first + 1 < last) {
            middle = (first + last) / 2;
            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] < target) {
                first = middle;
            } else {
                last = middle;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    // input
    int target;
    vector<int> valueVec;
    Input(target);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.search(valueVec, target);

    // output
    Output(ret);

    return 0;
}
