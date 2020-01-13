#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
     int reachingPoints(int sx, int sy) {
		int ret = 0;
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
    int ret = solution.reachingPoints(sx, sy);

    // output
    Output(ret);

    return 0;
}
