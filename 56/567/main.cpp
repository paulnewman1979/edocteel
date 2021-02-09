#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        vector<int> charCount(26, 0);
        int charUnmatched = 0, i, j, chIdx;
        for (i = 0; i < s1.length(); ++i) {
            chIdx = s1[i] - 'a';
            charCount[chIdx]++;
            if (charCount[chIdx] == 1) {
                ++charUnmatched;
            }
        }
        j = 0;
        for (i = 0; i < s2.length(); ++i) {
            chIdx = s2[i] - 'a';
            --charCount[chIdx];
            if (charCount[chIdx] == 0) {
                --charUnmatched;
                if (charUnmatched == 0) {
                    return true;
                }
            } else if (charCount[chIdx] < 0) {
                while (s2[j] != s2[i]) {
                    chIdx = s2[j] - 'a';
                    ++charCount[chIdx];
                    if (charCount[chIdx] == 1) {
                        ++charUnmatched;
                    }
                    ++j;
                }
                chIdx = s2[j] - 'a';
                ++charCount[chIdx];
                ++j;
            }
        }
        return false;
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
    bool ret = solution.checkInclusion(a, b);

    // output
    Output(ret);

    return 0;
}
