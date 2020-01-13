#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        int ret = 0;
        if (target == 0) return 0;
        else if (target < 0) target = -target;

        unsigned long long int sum = 0;
        ret = 0;
        while (sum < target) {
            ++ret;
            sum += ret;
        }
        while ((sum - target) % 2 == 1) {
            ++ret;
            sum += ret;
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
    int ret = solution.reachNumber(K);

    // output
    Output(ret);

    return 0;
}
