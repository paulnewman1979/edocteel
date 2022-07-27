#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

static const int MODULO = 1000000007;

class Solution {
public:
    int numTilings(int N) {
        int i;
        vector<long long int> aType(N + 1, 0);
        vector<long long int> bType(N + 1, 0);
        aType[0] = 1;
        bType[0] = 0;
        aType[1] = 1;
        bType[1] = 0;
        for (i = 2; i <= N; ++i) {
            aType[i] = (aType[i - 1] + aType[i - 2] + bType[i - 1] + bType[i - 1]) % MODULO;
            bType[i] = (aType[i - 2] + bType[i - 1]) % MODULO;
            //cout << "i=" << i << ", A=" << aType[i] << ", B=" << bType[i] << endl;
        }

        return aType[N];
    }
};

int main(int argc, char* argv[])
{
    // input
    int N;
    Input(N);

    // solution
    Solution solution;
    int ret = solution.numTilings(N);

    // output
    Output(ret);

    return 0;
}
