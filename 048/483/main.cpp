#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        string result;
        stringstream ss;
        int i, maxExpo, exp;
        unsigned long long int N = 0, base, newN;
        for (i = 0; i < n.length(); ++i) {
            N = N * 10 + (n[i] - '0');
        }
        maxExpo = log(N) / log(2);
        for (exp = maxExpo; exp >= 2; -- exp) {
            base = pow(N, 1.0/exp);
            newN = 1;
            for (i = 0; i < exp; ++i) {
                newN = newN * base + 1;
            }
            if (newN == N) {
                ss << base;
                return ss.str();
            }
        }
        ss << (N - 1);
        return ss.str();
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	string ret = solution.smallestGoodBase(str);

    // output
    Output(ret);

    return 0;
}
