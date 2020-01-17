#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ret(T.size(), 0);
        int i, j, curLow = 100;
        vector<vector<int>> preTemp(101);
        for (i = 0; i < T.size(); ++i) {
            if (T[i] > curLow) {
                for (j = curLow; j < T[i]; ++j) {
                    for (auto ipx : preTemp[j]) {
                        ret[ipx] = i - ipx;
                    }
                    preTemp[j].clear();
                }
            }
            preTemp[T[i]].push_back(i);
            curLow = T[i];
        }
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
    vector<int> ret = solution.dailyTemperatures(words);

    // output
    Output(ret);

    return 0;
}
