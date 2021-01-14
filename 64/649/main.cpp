#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = senate.length();
        int i, j, rCount = 0, dCount = 0;
        for (i = 0; i < len; ++i) {
            if (senate[i] == 'R') {
                ++rCount;
            } else {
                ++dCount;
            }
        }

        i = 0;
        while ((rCount > 0) && (dCount > 0)) {
            if (senate[i] == 'R') {
                j = i + 1;
                if (j == len) j = 0;
                while (senate[j] != 'D') {
                    ++j;
                    if (j == len) j = 0;
                }
                senate[j] = 'N';
                --dCount;
            } else if (senate[i] == 'D') {
                j = i + 1;
                if (j == len) j = 0;
                while (senate[j] != 'R') {
                    ++j;
                    if (j == len) j = 0;
                }
                senate[j] = 'N';
                --rCount;
            }
            ++i;
            if (i == len) i = 0;
        }

        return (rCount > 0) ? "Radiant" : "Dire";
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	string ret = solution.predictPartyVictory(str);

    // output
    Output(ret);

    return 0;
}
