#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        return true;
    }
};

int main(int argc, char* argv[])
{
    // Input
    int n;
    Input(n);

    // solution
    Solution solution;
    bool ret = solution.judgeSquareSum(n);

    // output
    Output(ret);

    return 0;
}
