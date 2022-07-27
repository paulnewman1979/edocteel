#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int size = nums.size(), i;
        vector<string> ret(size);
        vector<pair<int, int>> scorePos(size);
        for (i = 0; i < size; ++i) {
            scorePos[i].first = nums[i];
            scorePos[i].second = i;
        }
        //sort(scorePos.begin(), scorePos.end(), ScoreComp);
        sort(scorePos.begin(), scorePos.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.first > b.first; });
        i = 0;
        while ((i < size) && (i < 3)) {
            if (i == 0) {
                ret[scorePos[i].second] = "Gold Medal";
            } else if (i == 1) {
                ret[scorePos[i].second] = "Silver Medal";
            } else {
                ret[scorePos[i].second] = "Bronze Medal";
            }
            ++i;
        }
        while (i < size) {
            stringstream ss;
            ss << (i + 1);
            ret[scorePos[i].second] = ss.str();
            ++i;
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
    vector<string> ret = solution.findRelativeRanks(valueVec);

    // output
    Output(ret);

    return 0;
}
