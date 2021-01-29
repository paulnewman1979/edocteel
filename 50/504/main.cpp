#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (0 == num) return "0";
        bool isPositive = true;
        stringstream ss;
        int i = num, j;
        if (i < 0) {
            isPositive = false;
            i = -i;
        }
        while (i > 0) {
            ss << (i % 7);
            i /= 7;
        }
        string ret = ss.str();
        if (!isPositive) ret += "-";
        char tmp;
        for (i = 0, j = ret.length() - 1; i < j; ++i, --j) {
            tmp = ret[i];
            ret[i] = ret[j];
            ret[j] = tmp;
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int value;
    Input(value);

    // solution
    Solution solution;
    string ret = solution.convertToBase7(value);

    // output
    Output(ret);

    return 0;
}
