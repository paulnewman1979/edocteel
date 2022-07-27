#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (1 == num) return false;
        int sum = 1, sqrtN = sqrt(num), i;
        for (i = 2; i <= sqrtN; ++i) {
            if (num % i == 0) {
                sum += i;
                sum += num / i;
            }
        }
        return (sum == num);
    }
};

int main(int argc, char* argv[])
{
    // Input
    int n;
    Input(n);

    // solution
    Solution solution;
    bool ret = solution.checkPerfectNumber(n);

    // output
    Output(ret);

    return 0;
}
