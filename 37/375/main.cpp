#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> minAmount(n + 1, vector<int>(n + 1, -1));
        getMoneyAmount(1, n, minAmount);
        return minAmount[1][n];
    }

private:
    void getMoneyAmount(int start, int end, vector<vector<int>>& minAmount) {
        if (minAmount[start][end] == -1) {
            if (start == end) {
                minAmount[start][end] = 0;
            } else if (start + 1 == end) {
                minAmount[start][end] = start;
            } else {
                int min = INT_MAX, cur;
                for (int i = start + 1; i < end; ++i) {
                    getMoneyAmount(start, i - 1, minAmount);
                    getMoneyAmount(i + 1, end, minAmount);
                    cur = (minAmount[start][i - 1] < minAmount[i + 1][end]) ? 
                        (minAmount[i + 1][end] + i) : (minAmount[start][i - 1] + i);
                    if (cur < min) {
                        min = cur;
                    }
                }
                minAmount[start][end] = min;
            }
        }
    }
};

int main(int argc, char* argv[])
{
    // input
    int K;
    Input(K);

    // solution
    Solution solution;
    int ret = solution.getMoneyAmount(K);

    // output
    Output(ret);

    return 0;
}
