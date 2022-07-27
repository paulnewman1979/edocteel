#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int size = stones.size(), i, j, k;
        if (size <= 1) return true;
        if (stones[0] + 1 != stones[1]) return false;
        unordered_map<int, int> numPos;
        unordered_map<int, int>::iterator iter;
        vector<int> delta({-1, 0, 1});
        for (i = 0; i < size; ++i) {
            numPos[stones[i]] = i;
        }
        vector<set<int>> step(size);
        step[1].insert(1);
        for (int i = 1; i < size - 1; ++i) {
            for (int s : step[i]) {
                j = (s == 1) ? 1 : 0;
                for (; j < 3; ++j) {
                    k = stones[i] + s + delta[j];
                    iter = numPos.find(k);
                    if (iter != numPos.end()) {
                       step[iter->second].insert(s + delta[j]);
                    }
                }
            }
        }
        return (step.back().size() > 0);
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    bool ret = solution.canCross(valueVec);

    // output
    Output(ret);

    return 0;
}
