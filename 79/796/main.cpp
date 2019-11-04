#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) return false;
        string AA = A + A;
        return (AA.find(B) != string::npos);
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
    bool ret = solution.rotateString(a, b);

    // output
    Output(ret);

    return 0;
}
