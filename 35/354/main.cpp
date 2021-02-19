#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b) {
    return ((a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1])));
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size(), i, j, ret = 0;
        if (1 == size) return 1;
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> count(size, 1);
        for (i = 1; i < size; ++i) {
            j = i - 1;
            while ((j >= 0) && (envelopes[j][0] == envelopes[i][0])) --j;
            while (j >= 0) {
                if ((envelopes[i][1] > envelopes[j][1]) &&
                        (count[i] < count[j] + 1)) {
                    count[i] = count[j] + 1;
                }
                --j;
            }
            if (count[i] > ret) ret = count[i];
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.maxEnvelopes(valueGrid);

    // output
    Output(ret);

    return 0;
}
