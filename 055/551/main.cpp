#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        if (s.length() < 2) return true;
        // A -> 01
        // L -> 10
        // P -> 11
        int status = 0, i, aCount = 0;
        for (i = 0; i < s.length(); ++i) {
            switch(s[i]) {
              case 'A':
                ++aCount; if (aCount > 1) return false;
                status = ((status<<2)&0xf) + 1;
                break;
              case 'L':
                if ((status&0xf) == 10) return false;
                status = ((status<<2)&0xf) + 2;
                break;
              default:
                status = ((status<<2)&0xf) + 3;
            }
        }
        return true;
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	bool ret = solution.checkRecord(str);

    // output
    Output(ret);

    return 0;
}
