#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int ret = 0, i, j, k, l, m = forest.size(), n = forest[0].size();
        vector<int> values;
        unordered_map<int, pair<int, int>> valueToPos;
        pair<int, int> pos1, pos2;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    values.push_back(forest[i][j]);
                    pos1.first = i;
                    pos1.second = j;
                    valueToPos[forest[i][j]] = pos1;
                }
            }
        }
        sort(values.begin(), values.end());
        vector<pair<int, int>> todos;
        pos1.first = pos1.second = 0;
        for (k = 0; k < values.size(); ++k) {
            pos2 = valueToPos[values[k]];
            if (pos1 == pos2) continue;
            todos.clear();
            todos.push_back(pos1);
            vector<vector<int>> marks(m, vector<int>(n, 0));
            l = 1;
            while (todos.size() > 0) {
                vector<pair<int, int>> tmp;
                for (auto& todo: todos) {
                    i = todo.first; j = todo.second;
                    if ((i + 1 < m) && (forest[i + 1][j] > 0) && (marks[i + 1][j] ==0)) {
                        tmp.push_back(make_pair(i + 1, j));
                        marks[i + 1][j] = 1;
                    }
                    if ((i > 0) && (forest[i - 1][j] > 0) && (marks[i - 1][j] == 0)) {
                        tmp.push_back(make_pair(i - 1, j));
                        marks[i - 1][j] = 1;
                    }
                    if ((j + 1 < n) && (forest[i][j + 1] > 0) && (marks[i][j + 1] == 0)) {
                        tmp.push_back(make_pair(i, j + 1));
                        marks[i][j + 1] = 1;
                    }
                    if ((j > 0) && (forest[i][j - 1] > 0) && (marks[i][j - 1] == 0)) {
                        tmp.push_back(make_pair(i, j - 1));
                        marks[i][j - 1] = 1;
                    }
                }
                if (marks[pos2.first][pos2.second] == 1) break;
                todos.swap(tmp);
                ++l;
            }
            if (todos.size() > 0) {
                //cout << "to value " << values[k] << " distance=" << l << endl;
                ret += l;
            }
            else return -1;
            pos1 = pos2;
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
    int ret = solution.cutOffTree(valueGrid);

    // output
    Output(ret);

    return 0;
}
