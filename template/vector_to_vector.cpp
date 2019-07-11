#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words) {
        vector<string> ret;
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> words;
    Input(words);

    // solution
    Solution solution;
    vector<string> ret = solution.topKFrequent(words);

    // output
    Output(ret);

    return 0;
}
