#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    Solution() : primes(vector<int>({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})) {
    }

    int minSteps(int n) {
        if (1 == n) return 0;
        vector<int> factors;
        int i, j = n;
        for (i = 0; primes[i] * primes[i] <= n; ++i) {
            if (j % primes[i] == 0) {
                factors.push_back(primes[i]);
                j /= primes[i];
                --i;
            }
        }
        if (j == n) {
            return n;
        } else {
            if (j != 1) factors.push_back(j);
            j = 0;
            for (i = 0; i < factors.size(); ++i) {
                j += factors[i];
            }
        }
        return j;
    }

private:
    vector<int> primes;
};

int main(int argc, char* argv[])
{
    // input
    int K;
    Input(K);

    // solution
    Solution solution;
    int ret = solution.minSteps(K);

    // output
    Output(ret);

    return 0;
}
