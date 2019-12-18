#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> mark(graph.size(), 0);
        int markCount = 0;
        unordered_set<int> todo;
        unordered_set<int> tmp;
        while (markCount != graph.size()) {
            if (todo.size() == 0) {
                for (int i = 0; i < mark.size(); ++i) {
                    if (mark[i] == 0) {
                        mark[i] = 1;
                        markCount++;
                        todo.insert(i);
                        break;
                    }
                }
            }

            while (todo.size() > 0) {
                tmp.clear();
                for (auto i : todo) {
                    for (auto j : graph[i]) {
                        if (mark[j] == 0) {
                            mark[j] = 3 - mark[i];
                            tmp.insert(j);
                            markCount++;
                        } else if (mark[j] == mark[i]) {
                            return false;
                        }
                    }
                }
                todo.swap(tmp);
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
    bool ret = solution.isBipartite(valueGrid);

    // output
    Output(ret);

    return 0;
}
