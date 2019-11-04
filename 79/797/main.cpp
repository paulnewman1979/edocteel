#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> results;
        vector<int> cur;
        cur.push_back(0);
        checkGraph(graph, cur, results);
        return results;
    }

private:
    void checkGraph(const vector<vector<int>>& graph, 
            vector<int> cur,
            vector<vector<int>>& results) {
        if (cur.back() == graph.size() - 1) {
            results.push_back(cur);
            return;
        }

        for (auto i : graph[cur.back()]) {
            cur.push_back(i);
            checkGraph(graph, cur, results);
            cur.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    // input
    vector< vector<int> > edges;
    Input(edges);

    // solution
    Solution solution;
    vector<vector<int> > results = solution.allPathsSourceTarget(edges);

    // output
    Output(results);

    return 0;
}
