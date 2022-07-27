#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>> valueGrid) {
        vector<int> ret(valueGrid.size(), 0);
        vector<vector<int>> lrh(valueGrid.size(), vector<int>(3, 0));
        if (0 == valueGrid.size()) return ret;

        vector<pair<int, int>> lr;
        int i, j, left, right, height;
        ret[0] = valueGrid[0][1];
        lrh[0][0] = valueGrid[0][0];
        lrh[0][1] = valueGrid[0][0] + valueGrid[0][1];
        lrh[0][2] = valueGrid[0][1];

        for (i = 1; i < valueGrid.size(); ++i) {
            left = valueGrid[i][0];
            right = left + valueGrid[i][1];
            height = 0;
            for (j = 0; j < i; ++j) {
                if ((right > lrh[j][0]) &&
                        (left < lrh[j][1])) {
                    if (height < lrh[j][2]) height = lrh[j][2];
                }
            }
            height += valueGrid[i][1];
            ret[i] = (ret[i - 1] > height) ? ret[i - 1] : height;
            lrh[i][0] = left;
            lrh[i][1] = right;
            lrh[i][2] = height;
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
    vector<int> retVec = solution.fallingSquares(valueGrid);

    // output
    Output(retVec);

    return 0;
}

