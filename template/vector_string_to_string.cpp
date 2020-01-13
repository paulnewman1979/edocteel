#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string ret;
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    string value;
    vector<string> valueVec;
    Input(value);
    Input(valueVec);

    // solution
    Solution solution;
    string ret = solution.shortestCompletingWord(value, valueVec);

    // output
    Output(ret);

    return 0;
}
