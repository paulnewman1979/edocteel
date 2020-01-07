#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
		int ret = 0;
        for (int i = L; i <= R; ++i) {
            switch(countBits(i)) {
            case 2:
            case 3:
            case 5:
            case 7:
            case 11:
            case 13:
            case 17:
            case 19:
            case 21:
                ++ret;
                break;
            }
        }
		return ret;
    }

private:
    int countBits(int n) {
        int ret = ((n&0xaaaaaaaa)>>1) + (n&0x55555555);
        ret = ((ret&0xcccccccc)>>2) + (ret&0x33333333);
        ret = ((ret&0xf0f0f0f0)>>4) + (ret&0x0f0f0f0f);
        ret = ((ret&0xff00ff00)>>8) + (ret&0x00ff00ff);
        ret = ((ret&0xffff0000)>>16) + (ret&0x0000ffff);
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
    int ret = solution.countPrimeSetBits(sx, sy);

    // output
    Output(ret);

    return 0;
}
