#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double ret = 0.0;
        if (0 == poured) return 0.0;
        int i, row;
        vector<vector<double>> vols(100);
        for (i = 0; i < vols.size(); ++i) {
            vols[i].resize(i + 1, 0);
        }
        vols[0][0] = poured;

        bool anyFull = true;
        row = 0;
        while ((row < query_row) && anyFull) {
            ++row;
            anyFull = false;
            vols[row][0] = vols[row][row] = (vols[row - 1][0] > 1) ?
                (vols[row - 1][0] - 1) / 2 : 0;
            for (i = 1; i < row; ++i) {
                vols[row][i] += (vols[row - 1][i - 1] > 1) ? (vols[row - 1][i - 1] - 1)/2 : 0;
                vols[row][i] += (vols[row - 1][i] > 1) ? (vols[row - 1][i] - 1)/2 : 0;
            }
            if (vols[row][row / 2] > 1.0) {
                anyFull = true;
            }
        }
        if (row == query_row) {
            ret = (vols[row][query_glass] > 1) ? 1.0 : vols[row][query_glass];
        } else {
            ret = 0.0;
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int poured, query_row, query_glass;
    Input(poured);
    Input(query_row);
    Input(query_glass);

    // solution
    Solution solution;
	double ret = solution.champagneTower(poured, query_row, query_glass);

    // output
    Output(ret);

    return 0;
}
