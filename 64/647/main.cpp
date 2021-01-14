#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int i, j, k, ret = 0;
        for (i = 0; i < s.length(); ++i) {
            j = i - 1;
            k = i + 1;
            ++ret;
            while (((j >=0) && (k < s.length()) && (s[j] == s[k]))) {
                ++ret;
                --j;
                ++k;
            }
        }
        for (i = 0; i < s.length() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                ++ret;
                j = i - 1;
                k = i + 2;
                while (((j >= 0) && (k < s.length()) && (s[j] == s[k]))) {
                    ++ret;
                    --j;
                    ++k;
                }
            }
        }
        return ret;
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	int ret = solution.countSubstrings(str);

    // output
    Output(ret);

    return 0;
}
