#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ret(m * n);
        int i, j, k, l = 0;
        for (k = 0; k < m + n - 1; ++k) {
            if (k % 2 == 1) {
                for (i = max(0, k + 1 - n); i <= min(k, m - 1); ++i) {
                    j = k - i;
                    ret[l++] = mat[i][j];
                }
            } else {
                for (i = min(k, m - 1); i >= max(0, k + 1 - n); --i) {
                    j = k - i;
                    ret[l++] = mat[i][j];
                }
            }
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
    vector<int> retVec = solution.findDiagonalOrder(valueGrid);

    // output
    Output(retVec);

    return 0;
}

