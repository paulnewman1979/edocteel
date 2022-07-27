#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10) return -1;
        unsigned long long int p = n;
        vector<int> digits;
        int i, digit;
        digits.push_back(p % 10);
        p /= 10;
        while (p > 0) {
            digit = p % 10;
            p /= 10;
            if (digit < digits.back()) break;
            digits.push_back(digit);
        }
        if (digit >= digits.back()) return -1;
        else {
            i = 0;
            while (digits[i] <= digit) ++i;
            swap(digits[i], digit);
            p = p * 10 + digit;
            for (i = 0; i < digits.size(); ++i) {
                p = p * 10 + digits[i];
            }
            if (p > ((1ULL<<31) - 1)) return -1;
            else return p;
        }
    }
};

int main(int argc, char* argv[])
{
    // input
    int K;
    Input(K);

    // solution
    Solution solution;
    int ret = solution.nextGreaterElement(K);

    // output
    Output(ret);

    return 0;
}
