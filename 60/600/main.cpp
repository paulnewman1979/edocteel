#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        int i, ret = 0, size = 0;
        vector<unsigned int> a(33, 0), b(33, 0);
        a[0] = 1; b[0] = 1; a[1] = 2; b[1] = 1;
        for (i = 2; i <= 32; ++i) {
            a[i] = a[i - 1] + b[i - 1];
            b[i] = a[i - 2] + b[i - 2];
        }
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 2);
            num = num / 2;
        }
        size = digits.size();
        ret = a[size - 1];
        for (i = size - 2; i >= 0; --i) {
            if (digits[i] == 1) {
                ret += a[i];
                if (digits[i + 1] == 1) break;
            }
        }
        if (i < 0) ++ret;

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
    int ret = solution.findIntegers(K);

    // output
    Output(ret);

    return 0;
}
