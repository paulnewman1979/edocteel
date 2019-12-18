#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int ret = 0, i;
        vector<int> mark(N + 1, 0);
        int validDigits[] = {0, 0, 1, 3, 3, 1, 1, 3, 0, 1};
        for (i = 1; ((i < 10) && (i <= N)); ++i) {
            mark[i] = validDigits[i];
            if (mark[i] == 1) ++ret;
        }
        for (i = 10; i <= N; ++i) {
            mark[i] = (mark[i/10] | validDigits[i%10]);
            if (mark[i] == 1) ++ret;
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int K;
    Input(K);

    // solution
    Solution solution;
    int ret = solution.rotatedDigits(K);

    // output
    Output(ret);

    return 0;
}
