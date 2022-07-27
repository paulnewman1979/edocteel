#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        if (0 == num) return 0;
        int i, j;
        vector<int> digits;
        i = num;
        while (i > 0) {
            digits.push_back(i % 10);
            i = i/10;
        }
        vector<int> pos(10, -1);
        int maxDigits = 0;
        for (i = 0; i < digits.size(); ++i) {
            if (digits[i] > maxDigits) {
                maxDigits = digits[i];
            }
            if (pos[digits[i]] == -1) {
                pos[digits[i]] = i;
            }
        }
        for (i = digits.size() - 1; i > 0; --i) {
            if (digits[i] < maxDigits) {
                int curDigit = digits[i];
                for (j = maxDigits; j > curDigit; --j) {
                    if ((pos[j] != -1) && (pos[j] < i)) {
                        int tmp = digits[i];
                        digits[i] = j;
                        digits[pos[j]] = tmp;
                        break;
                    }
                }
                if (j > curDigit) {
                    break;
                }
            }
        }

        int ret = 0;
        for (i = digits.size() - 1; i >= 0; --i) {
            ret = ret * 10 + digits[i];
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
    int ret = solution.maximumSwap(K);

    // output
    Output(ret);

    return 0;
}
