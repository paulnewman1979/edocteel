#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (0 == n) return 0;
        int i, a = 0, b = 1;
        for (i = 1; i < (n + 1) / 2; ++i) {
            a = a + b;
            b = a + b;
        }
        return (n % 2 == 1) ? b : a + b;
    }
};

int main(int argc, char* argv[])
{
    // input
    int K;
    Input(K);

    // solution
    Solution solution;
    int ret = solution.fib(K);

    // output
    Output(ret);

    return 0;
}
