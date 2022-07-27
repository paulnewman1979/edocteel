#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> typeSet;
        int ret = 0, n = candyType.size(), halfN = n / 2;
        for (auto t : candyType) {
            if (typeSet.find(t) == typeSet.end()) {
                ++ret;
                if (ret >= halfN) return halfN;
                typeSet.insert(t);
            }
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
    int ret = solution.distributeCandies(valueVec);

    // output
    Output(ret);

    return 0;
}
