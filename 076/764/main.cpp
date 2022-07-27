#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int i, j, k, tmp, start, ret = 0;
        vector<vector<int>> mark(N, vector<int>(N, 1));
        vector<vector<int>> maxPlus(N, vector<int>(N, 0));
        for (auto p : mines) {
            mark[p[0]][p[1]] = 0;
        }
        for (i = 0; i < N; ++i) {
            start = -1;
            for (j = 0; j < N; ++j) {
                if (mark[i][j] == 0) {
                    if (start != -1) {
                        //cout << i << " " << j << endl;
                        for (k = start; k < j; ++k) {
                            maxPlus[i][k] = min(k - start + 1, j - k);
                            //cout << "maxPlus[" << i << "," << k << "]=" << maxPlus[i][k] << endl;
                        }
                    }
                    start = -1;
                } else if (start == -1) {
                    start = j;
                }
            }
            if (start != -1) {
                for (k = start; k < N; ++k) {
                    maxPlus[i][k] = min(k - start + 1, N - k);
                    //cout << i << " " << N << endl;
                    //cout << "maxPlus[" << i << "," << k << "]=" << maxPlus[i][k] << endl;
                }
            }
        }

        ret = 0;
        for (j = 0; j < N; ++j) {
            start = -1;
            for (i = 0; i < N; ++i) {
                if (mark[i][j] == 0) {
                    if (start != -1) {
                        //cout << i << " " << j << endl;
                        for (k = start; k < i; ++k) {
                            tmp = min(k - start + 1, i - k);
                            if (maxPlus[k][j] > tmp) maxPlus[k][j] = tmp;
                            //cout << "maxPlus[" << i << "," << k << "]=" << maxPlus[i][k] << endl;
                            if (maxPlus[k][j] > ret) ret = maxPlus[k][j];
                        }
                    }
                    start = -1;
                } else if (start == -1) {
                    start = i;
                }
            }
            if (start != -1) {
                for (k = start; k < N; ++k) {
                    tmp = min(k - start + 1, N - k);
                    if (maxPlus[k][j] > tmp) maxPlus[k][j] = tmp;
                    //cout << "maxPlus[" << k << "," << j << "]=" << maxPlus[k][j] << endl;
                    if (maxPlus[k][j] > ret) ret = maxPlus[k][j];
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
    int ret = solution.orderOfLargestPlusSign(value, valueGrid);

    // output
    Output(ret);

    return 0;
}
