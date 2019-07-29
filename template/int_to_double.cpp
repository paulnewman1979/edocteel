#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    double soupServings(int N) {
        return 0.0;
    }
};

int main(int argc, char* argv[])
{
    // input
    int value;
    Input(value);

    // solution
    Solution solution;
    double ret = solution.soupServings(value);

    // output
    Output(ret);

    return 0;
}
