#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ret = 0, index;
        vector<int> count(2, 0);
        if (s[0] == '0') {
            index = 0;
            count[0] = 1;
        } else {
            index = 1;
            count[1] = 1;
        }
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                count[index]++;
            } else {
                ret += (count[index] > count[1 - index]) ? count[1 - index] : count[index];
                index = 1 - index;
                count[index] = 1;
            }
        }
        ret += (count[index] > count[1 - index]) ? count[1 - index] : count[index];
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
	int ret = solution.countBinarySubstrings(str);

    // output
    Output(ret);

    return 0;
}
