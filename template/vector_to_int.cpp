#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int xorGame(vector<string>& nums) {
        int ret = 0;
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.xorGame(valueVec);

    // output
    Output(ret);

    return 0;
}
