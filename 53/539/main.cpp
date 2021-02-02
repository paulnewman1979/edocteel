#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        int value, i, tmp;
        for (const auto& t : timePoints) {
            tmp = 0;
            for (i = 0; i < t.length(); ++i) {
                if (t[i] != ':') {
                    tmp = tmp * 10 + (t[i] - '0');
                } else {
                    value = tmp * 60;
                    tmp = 0;
                }
            }
            value += tmp;
            times.push_back(value);
        }
        value = 1440;
        sort(times.begin(), times.end());
        for (i = 0; i < times.size() - 1; ++i) {
            if (times[i + 1] - times[i] < value) value = times[i + 1] - times[i];
        }
        if (times[0] + 1440 - times[times.size() - 1] < value) {
            value = times[0] + 1440 - times[times.size() - 1];
        }
        return value;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.findMinDifference(valueVec);

    // output
    Output(ret);

    return 0;
}
