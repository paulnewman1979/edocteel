#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.length() < b.length()) {
            return b.length();
        } else if (a.length() > b.length()) {
            return a.length();
        } else if (a == b) {
            return -1;
        } else {
            return a.length();
        }
	}
};

int main(int argc, char* argv[])
{
    // input
    string a, b;
    Input(a);
    Input(b);

    // solution
    Solution solution;
	int ret = solution.findLUSlength(a, b);

    // output
    Output(ret);

    return 0;
}
