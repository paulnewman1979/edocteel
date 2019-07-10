#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& words) {
        vector<int> ret;
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> words;
    Input(words);

    // solution
    Solution solution;
    vector<int> ret = solution.topKFrequent(words);

    // output
    Output(ret);

    return 0;
}
