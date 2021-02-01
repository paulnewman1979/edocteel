#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int sPos, dPos;
        sort(d.begin(), d.end(), [](string& a, string& b) { return ((a.length() > b.length()) || ((a.length() == b.length()) && (a < b))); });
        for (auto& subD : d) {
            dPos = 0;
            for (sPos = 0; sPos < s.length(); ++sPos) {
                if (s[sPos] == subD[dPos]) {
                    ++dPos;
                    if (dPos >= subD.length()) return subD;
                }
            }
        }

        return "";
    }
};

int main(int argc, char* argv[])
{
    // input
    string value;
    vector<string> valueVec;
    Input(value);
    Input(valueVec);

    // solution
    Solution solution;
    string ret = solution.findLongestWord(value, valueVec);

    // output
    Output(ret);

    return 0;
}
