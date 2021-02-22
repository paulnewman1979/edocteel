#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m < 1) return 0;
        int n = matrix[0].size();
        if (n < 1) return 0;

        int ret = 0, i, j;
        bool isNotBigger;
        vector<vector<int>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        vector<vector<int>> marks(m, vector<int>(n, -1));
        vector<pair<int, int>> todo;
        vector<pair<int, int>> tmpTodo;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                isNotBigger = true;
                for (auto& d : dir) {
                    if ((i + d[0] >= 0) && (i + d[0] < m) &&
                            (j + d[1] >= 0) && (j + d[1] < n) &&
                            (matrix[i][j] > matrix[i + d[0]][j + d[1]])) {
                        isNotBigger = false;
                    }
                }
                if (isNotBigger) {
                    todo.push_back(pair(i, j));
                    marks[i][j] = 0;
                }
            }
        }

        while (todo.size() > 0) {
            tmpTodo.clear();
            for (auto& t : todo) {
                i = t.first; j = t.second;
                for (auto& d : dir) {
                    if ((i + d[0] >= 0) && (i + d[0] < m) &&
                            (j + d[1] >= 0) && (j + d[1] < n) &&
                            (matrix[i + d[0]][j + d[1]] > matrix[i][j]) &&
                            (marks[i + d[0]][j + d[1]] < marks[i][j] + 1)) {
                        marks[i + d[0]][j + d[1]] = marks[i][j] + 1;
                        tmpTodo.push_back(pair(i + d[0], j + d[1]));
                    }
                }
            }
            todo.swap(tmpTodo);
        }

        ret = 0;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (marks[i][j] > ret) ret = marks[i][j];
            }
        }

        return (ret + 1);
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.longestIncreasingPath(valueGrid);

    // output
    Output(ret);

    return 0;
}
