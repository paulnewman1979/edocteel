#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> results;
        return results;
    }
};

int main(int argc, char* argv[])
{
    // input
    string S;
    Input(S);

    // solution
    Solution solution;
    vector<string> ret = solution.letterCasePermutation(S);

    // output
    Output(ret);

    return 0;
}
