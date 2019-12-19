#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ret = 0;
        unordered_map<int, int> ansCount;
        for (auto i : answers) {
            ansCount[i]++;
        }
        for (auto i : ansCount) {
            ret += ((i.second + i.first) / (i.first + 1)) * (i.first + 1);
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.numRabbits(valueVec);

    // output
    Output(ret);

    return 0;
}
