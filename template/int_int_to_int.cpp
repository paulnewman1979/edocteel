#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
     bool reachingPoints(int sx, int sy) {
		bool ret = 0;
		return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int sx, sy;
    Input(sx);
    Input(sy);

    // solution
    Solution solution;
    bool ret = solution.reachingPoints(sx, sy);

    // output
    Output(ret);

    return 0;
}
