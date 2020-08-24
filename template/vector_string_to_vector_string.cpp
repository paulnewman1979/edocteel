#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ret;
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
    vector<string> ret = solution.removeComments(valueVec);

    // output
    Output(ret);

    return 0;
}
