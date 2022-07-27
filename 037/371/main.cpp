#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
     	return _getSum(a, b, 64);
    }

private:
    int _getSum(int a, int b, int times) {
        int c = (a&b&0x7fffffff)<<1;
        int d = a^b;
        return ((times > 0) && (c != 0)) ? _getSum(c, d, times - 1) : (c | d);
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
    int ret = solution.getSum(sx, sy);

    // output
    Output(ret);

    return 0;
}
