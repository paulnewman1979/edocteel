#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int i, j;
        int count = 0;
        int sum = 0;
        for (i = 0; i + 2 < grid.size(); ++i) {
            for (j = 0; j + 2 < grid[0].size(); ++j) {
                sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                if ((grid[i][j] <= 9) && (grid[i][j] >= 1) &&
                        (grid[i][j+1] <= 9) && (grid[i][j+1] >= 1) &&
                        (grid[i][j+2] <= 9) && (grid[i][j+2] >= 1) &&
                        (grid[i+1][j] <= 9) && (grid[i+1][j] >= 1) &&
                        (grid[i+1][j+1] <= 9) && (grid[i+1][j+1] >= 1) &&
                        (grid[i+1][j+2] <= 9) && (grid[i+1][j+2] >= 1) &&
                        (grid[i+2][j] <= 9) && (grid[i+2][j] >= 1) &&
                        (grid[i+2][j+1] <= 9) && (grid[i+2][j+1] >= 1) &&
                        (grid[i+2][j+2] <= 9) && (grid[i+2][j+2] >= 1) &&
                        (grid[i][j] != grid[i][j+2]) &&
                        (grid[i][j] != grid[i+2][j]) &&
                        (sum == (grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2])) &&
                        (sum == (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2])) &&
                        (sum == (grid[i][j] + grid[i+1][j] + grid[i+2][j])) &&
                        (sum == (grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1])) &&
                        (sum == (grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2])) &&
                        (sum == (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2])) &&
                        (sum == (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j]))) {
                    ++count;
                }
            }
        }
        return count;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector< vector<int> > valueGrid;

    // variable
    int n;
    int nn;
    vector<int> valueLine;
    int value;

    // input
    cin >> n;
    while (n-- > 0) {
        cin >> nn;
        valueLine.clear();
        while (nn-- > 0) {
            cin >> value;
            valueLine.push_back(value);
        }
        valueGrid.push_back(valueLine);
    }

    Solution solution;
    cout << solution.numMagicSquaresInside(valueGrid) << endl;

    return 0;
}
