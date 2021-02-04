#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string str;
        return str;
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
