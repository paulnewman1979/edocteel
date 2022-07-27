#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        int ret = 0, i = 1, j;
        for (j = 2; j <= N; ++j) {
            i=i<<1;
        }
        i=i>>1;
        while (i > 0) {
            if (K <= i) {
                ret = (ret == 0) ? 0 : 1;
            } else {
                ret = (ret == 0) ? 1 : 0;
                K -= i;
            }
            i = i>>1;
        }
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
    int ret = solution.kthGrammar(sx, sy);

    // output
    Output(ret);

    return 0;
}
