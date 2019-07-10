#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "Input.hh"
#include "Output.hh"

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        return 0;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> values;
    Input(values);

    // solution
    Solution solution;
    int ret = solution.numSpecialEquivGroups(values);

    // output
    Output(ret);

    return 0;
}
