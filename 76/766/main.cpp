#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int i, j;
        for (j = 0; j < colSize; ++j) {
            for (i = 1; (i < rowSize) && (i < colSize - j); ++i) {
                if (matrix[i][i + j] != matrix[0][j]) return false;
            }
        }
        for (i = 1; i < rowSize; ++i) {
            for (j = 1; (j < colSize) && (j < rowSize - i); ++j) {
                if (matrix[i + j][j] != matrix[i][0]) return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    bool ret = solution.isToeplitzMatrix(valueGrid);

    // output
    Output(ret);

    return 0;
}
