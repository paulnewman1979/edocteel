#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int n = N;
        int ret = 0, i, j;
        vector<int> nDigits;
        while (n > 0) {
            nDigits.push_back(n % 10);
            n = n / 10;
        }
        i = nDigits.size() - 1;
        while ((i > 0) && (nDigits[i] <= nDigits[i - 1])) --i;
        if (0 == i) return N;

        for (j = i - 1; j >= 0; --j) nDigits[j] = 9;
        nDigits[i] -= 1;

        j = i;
        while ((j + 1 < nDigits.size()) && (nDigits[j + 1] > nDigits[j])) {
            nDigits[j] = 9;
            --nDigits[j + 1];
            ++j;
        }

        for (i = nDigits.size() - 1; i >= 0; --i) {
            ret = ret * 10 + nDigits[i];
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
    int ret = solution.monotoneIncreasingDigits(K);

    // output
    Output(ret);

    return 0;
}
