#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ret = 0;
        return ret;
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
    int ret = solution.numJewelsInStones(a, b);

    // output
    Output(ret);

    return 0;
}
