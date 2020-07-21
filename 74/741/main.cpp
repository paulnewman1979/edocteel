#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size(), i, j, k, index = 0, prevIndex;
        vector<vector<vector<int>>> maxCount(2, vector<vector<int>>(N, vector<int>(N, 0)));
        maxCount[index][0][0] = grid[0][0];

        for (k = 1; k < N; ++k) {
            //cout << "k=" << k << endl;
            prevIndex = index;
            index = 1 - index;
            for (i = 0; i <= k; ++i) {
                for (j = i; j <= k; ++j) {
                    if ((grid[i][k - i] == -1) || (grid[j][k - j] == -1)) {
                        maxCount[index][i][j] = -INT_MAX;
                    } else {
                        int value = (i == j) ? grid[i][k - i] : (grid[i][k - i] + grid[j][k - j]);
                        maxCount[index][i][j] = maxNum(
                                (i > 0) ? (maxCount[prevIndex][i - 1][j - 1] + value) : -INT_MAX,
                                (j < k) ? (maxCount[prevIndex][i][j] + value) : -INT_MAX,
                                (j > i) ? (maxCount[prevIndex][i][j - 1] + value) : -INT_MAX,
                                ((i > 0) && (j < k)) ? (maxCount[prevIndex][i - 1][j] + value) : -INT_MAX);
                    }
                    //cout << "i=" << i << " j=" << j << " " << maxCount[index][i][j] << endl;
                }
            }
        }
        for (k = N; k < 2*N - 1; ++k) {
            //cout << "k=" << k << endl;
            prevIndex = index;
            index = 1 - index;
            for (i = k + 1 - N; i < N; ++i) {
                for (j = i; j < N; ++j) {
                    if ((grid[i][k - i] == -1) || (grid[j][k - j] == -1)) {
                        maxCount[index][i][j] = -INT_MAX;
                    } else {
                        int value = (i == j) ? grid[i][k - i] : grid[i][k - i] + grid[j][k - j];
                        maxCount[index][i][j] = maxNum(
                                maxCount[prevIndex][i - 1][j - 1] + value,
                                maxCount[prevIndex][i][j] + value,
                                (j > i) ? (maxCount[prevIndex][i][j - 1] + value) : -INT_MAX,
                                maxCount[prevIndex][i - 1][j] + value);
                    }
                    //cout << "i=" << i << " j=" << j << " " << maxCount[index][i][j] << endl;
                }
            }
        }
        
        return (maxCount[index][N - 1][N - 1] < 0) ? 0 : maxCount[index][N - 1][N - 1];
    }

private:
    inline int maxNum(int a, int b, int c, int d) {
        int ret = max(max(a, b), max(c, d));
        return (ret < 0) ? -INT_MAX : ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.cherryPickup(valueGrid);

    // output
    Output(ret);

    return 0;
}
