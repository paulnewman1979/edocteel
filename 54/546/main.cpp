#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int size = boxes.size(), i, j, n;
        vector<pair<int, int>> nb;
        j = 0;
        for (i = 1; i < size; ++i) {
            if (boxes[i] != boxes[j]) {
                nb.push_back(pair(boxes[j], i - j));
                j = i;
            }
        }
        nb.push_back(pair(boxes[j], i - j));

        n = nb.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(size, 0)));
        maxPoints(nb, 0, n - 1, 0);
        return dp[0][n - 1][0];
    }

private:
    int maxPoints(vector<pair<int, int>>& nb,
            int start,
            int end,
            int k) {
        if (start > end) return 0;
        else {
            int& maxRes = dp[start][end][k];
            if (maxRes == 0) {
                if (start == end) {
                    dp[start][end][k] = (k + nb[start].second) * (k + nb[start].second);
                } else {
                    maxRes = maxPoints(nb, start, end - 1, 0) + (k + nb[end].second) * (k + nb[end].second);
                    for (int i = start; i < end; ++i) {
                        if (nb[i].first == nb[end].first)
                            maxRes = max(maxRes,
                                    maxPoints(nb, start, i, k + nb[end].second) + maxPoints(nb, i + 1, end - 1, 0));
                    }
                }
            }
            return maxRes;
        }
    }

private:
    vector<vector<vector<int>>> dp;
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.removeBoxes(valueVec);

    // output
    Output(ret);

    return 0;
}
