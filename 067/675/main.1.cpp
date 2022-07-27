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
        int m = forest.size(), n = forest[0].size(), size = m * n, treeCount = 0;
        int i, j, distance, pos1, pos2;
        unordered_map<int, int> valueToPos;
        vector<int> values;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (forest[i][j] > 0) {
                    ++size;
                    if (forest[i][j] > 1) {
                        ++treeCount;
                        valueToPos[forest[i][j]] = i * n + j;
                        values.push_back(forest[i][j]);
                    }
                }
            }
        }
        sort(values.begin(), values.end());

        vector<vector<int>> distances(size, vector<int>(size, INT_MAX));
        for (i = 0; i < size; ++i) distances[i][i] = 0;
        vector<unordered_set<int>> connect(size);
        vector<pair<int, int>> todos;
        int update = 0;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (forest[i][j] > 0) {
                    pos1 = i * n + j;
                    if ((i < m - 1) && (forest[i + 1][j] > 0)) {
                        pos2 = pos1 + n;
                        todos.push_back(make_pair(pos1, pos2));
                        distances[pos1][pos2] = 1;
                        distances[pos2][pos1] = 1;
                        //cout << "add: (" << pos1 << ", " << pos2 << ") =>\t1" << endl;
                        ++update;
                    }
                    if ((j < n - 1) && (forest[i][j + 1] > 0)) {
                        pos2 = pos1 + 1;
                        todos.push_back(make_pair(pos1, pos2));
                        distances[pos1][pos2] = 1;
                        distances[pos2][pos1] = 1;
                        //cout << "add: (" << pos1 << ", " << pos2 << ") =>\t1" << endl;
                        ++update;
                    }
                }
            }
        }

        while (todos.size() > 0) {
            //cout << "round:" << endl;
            vector<pair<int, int>> tmp;
            for (auto& todo: todos) {
                pos1 = todo.first;
                pos2 = todo.second;
                connect[pos1].insert(pos2);
                connect[pos2].insert(pos1);
                for (auto& connectPos: connect[pos1]) {
                    distance = distances[connectPos][pos1] + distances[pos1][pos2];
                    if (distances[connectPos][pos2] > distance) {
                        tmp.push_back(make_pair(connectPos, pos2));
                        distances[connectPos][pos2] = distance;
                        distances[pos2][connectPos] = distance;
                        //cout << "add: (" << pos2 << ", " << connectPos << ") =>\t" << distance << endl;
                    }
                }
                for (auto& connectPos: connect[pos2]) {
                    distance = distances[connectPos][pos2] + distances[pos2][pos1];
                    if (distances[connectPos][pos1] > distance) {
                        tmp.push_back(make_pair(connectPos, pos1));
                        distances[connectPos][pos1] = distance;
                        distances[pos1][connectPos] = distance;
                        //cout << "add: (" << pos1 << ", " << connectPos << ") =>\t " << distance << endl;
                    }
                }
            }
            todos.swap(tmp);
            //cout << endl;
        }

        int ret = 0;
        pos1 = 0;
        for (i = 0; i < values.size(); ++i) {
            pos2 = valueToPos[values[i]];
            distance = distances[pos1][pos2];
            //cout << "final: (" << pos1 << ", " << pos2 << ") =>\t" << distance << endl;
            if (distance < INT_MAX) {
                ret += distance;
            } else {
                return -1;
            }
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
