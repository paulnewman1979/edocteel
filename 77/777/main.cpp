#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int sIndex = 0, eIndex = 0, len = start.length();
        while ((sIndex < len) && (eIndex < len)) {
            while ((sIndex < len) && (start[sIndex] == 'X')) {
                ++sIndex;
            }
            while ((eIndex < len) && (end[eIndex] == 'X')) {
                ++eIndex;
            }
            if ((sIndex < len) && (eIndex < len)) {
                if (start[sIndex] == end[eIndex]) {
                    if (start[sIndex] == 'L') {
                        if (sIndex < eIndex) {
                            return false;
                        }
                    } else {
                        if (sIndex > eIndex) {
                            return false;
                        }
                    }
                    ++sIndex;
                    ++eIndex;
                } else {
                    return false;
                }
            } else if ((sIndex == len) && (eIndex == len)) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    // input
    string a;
    string b;
    Input(a);
    Input(b);

    // solution
    Solution solution;
    bool ret = solution.canTransform(a, b);

    // output
    Output(ret);

    return 0;
}
