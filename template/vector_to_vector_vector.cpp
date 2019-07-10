#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > ret;
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> nums;
    Input(nums);

    // solution
    Solution solution;
    vector<vector<int>> ret = solution.subsets(nums);

    // output
    Output(ret);

    return 0;
}
