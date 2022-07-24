#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (0 == n) return 1;
        vector<int> A(n + 1), B(n + 1);
        A[0] = 0; B[0] = 0;
        A[1] = 1; B[1] = 9;
        int total = 10, i = 2;
        for (; i <= n; ++i) {
            B[i] = B[i - 1] * (10 - i);
            A[i] = A[i - 1] * (11 - i) + B[i - 2] * (11 - i);
            total += A[i] + B[i];
        }
        return total;
    }
};

int main(int argc, char* argv[])
{
    // input
    int n;
    Input(n);

    // solution
    Solution solution;
    int ret = solution.countNumbersWithUniqueDigits(n);

    // output
    Output(ret);

    return 0;
}
