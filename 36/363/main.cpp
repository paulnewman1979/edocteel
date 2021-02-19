#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (0 == m) return 0;
        int n = matrix[0].size();
        if (0 == n) return 0;

        int curSum = 0, i, j, p;
        set<int> sums;
        set<int>::const_iterator iter;
        vector<int> lineSum(m);
        int ret = INT_MIN;
        for (j = 0; j < n; ++j) {
            sums.clear();
            sums.insert(0);
            curSum = 0;
            for (i = 0; i < m; ++i) {
                lineSum[i] = matrix[i][j];
                curSum += lineSum[i];
                iter = sums.lower_bound(curSum - k);
                if ((iter != sums.end()) && (curSum - (*iter) > ret)) ret = curSum - (*iter);
                sums.insert(curSum);
            }
            for (p = j + 1; p < n; ++p) {
                curSum = 0;
                sums.clear();
                sums.insert(0);
                for (i = 0; i < m; ++i) {
                    lineSum[i] += matrix[i][p];
                    curSum += lineSum[i];
                    iter = sums.lower_bound(curSum - k);
                    if ((iter != sums.end()) && (curSum - (*iter) > ret)) ret = curSum - (*iter);
                    sums.insert(curSum);
                }
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int value;
    vector<vector<int>> valueGrid;
    Input(value);
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.maxSumSubmatrix(valueGrid, value);

    // output
    Output(ret);

    return 0;
}
