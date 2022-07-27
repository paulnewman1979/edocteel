#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> neighbors({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        const int xSize = matrix.size();
        const int ySize = matrix[0].size();
        int x, y;
        vector<vector<int>> results(xSize, vector<int>(ySize, -1));
        vector<pair<int, int>> todo;
        vector<pair<int, int>> tmp;
        for (x = 0; x < xSize; ++x) {
            for (y = 0; y < ySize; ++y) {
                if (matrix[x][y] == 0) {
                    results[x][y] = 0;
                    todo.push_back(pair(x, y));
                }
            }
        }
        int distance = 1;
        while (todo.size() > 0) {
            tmp.clear();
            for (const auto& p : todo) {
                for (const auto& n :neighbors) {
                    x = p.first + n[0];
                    y = p.second + n[1];
                    if ((x >= 0) && (x < xSize) && (y >= 0) && (y < ySize) && (results[x][y] == -1)) {
                        results[x][y] = distance;
                        tmp.push_back(pair(x, y));
                    }
                }
            }
            todo.swap(tmp);
            ++distance;
        }

        return results;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    vector<vector<int>> results = solution.updateMatrix(valueGrid);

    // output
    Output(results);

    return 0;
}
