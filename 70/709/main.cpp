#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        string ret = str;
        for (auto& ch: ret) {
            if ((ch >= 'A') && (ch <= 'Z')) ch = ch - 'A' + 'a';
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
	string ret = solution.toLowerCase(str);

    // output
    Output(ret);

    return 0;
}
