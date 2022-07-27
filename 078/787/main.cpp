#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int k = 0;
        vector<int> leastCost(n, INT_MAX);
        vector<vector<pair<int, int>>> routes(n);
        unordered_set<int> todo;
        for (auto i : flights) {
            routes[i[0]].push_back(make_pair(i[1], i[2]));
        }
        todo.insert(src);
        leastCost[src] = 0;
        while ((k <= K) && (todo.size() > 0)) {
            unordered_map<int, int> tmp;
            for (auto i : todo) {
                for (auto j : routes[i]) {
                    if (leastCost[i] + j.second < leastCost[j.first]) {
                        if ((tmp.find(j.first) == tmp.end()) ||
                                (leastCost[i] + j.second < tmp[j.first])) {
                            tmp[j.first] = leastCost[i] + j.second;
                            //cout << "todo: " << j.first << ", " << tmp[j.first] << endl;
                        }
                    }
                }
            }
            todo.clear();
            for (auto i : tmp) {
                todo.insert(i.first);
                leastCost[i.first] = i.second;
            }
            ++k;
        }

        return (leastCost[dst] != INT_MAX) ? leastCost[dst] : -1;
    }
};

int main(int argc, char* argv[])
{
    // input
    int n, src, dst, K;
    vector<vector<int>> valueGrid;
    Input(n);
    Input(valueGrid);
    Input(src);
    Input(dst);
    Input(K);

    // solution
    Solution solution;
    int ret = solution.findCheapestPrice(n, valueGrid, src, dst, K);

    // output
    Output(ret);

    return 0;
}
