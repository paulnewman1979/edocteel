#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ret;
        vector<vector<int>> invertedGraph(graph.size());
        int i;
        vector<int> noOutEdgeNode;
        vector<int> outEdgeNodeCount(graph.size(), 0);
        for (i = 0; i < graph.size(); ++i) {
            if (graph[i].size() > 0) {
                outEdgeNodeCount[i] = graph[i].size();
                for (auto k : graph[i]) {
                    invertedGraph[k].push_back(i);
                }
            } else {
                outEdgeNodeCount[i] = 0;
                noOutEdgeNode.push_back(i);
                ret.push_back(i);
            }
        }
        while (noOutEdgeNode.size() > 0) {
            i = noOutEdgeNode.back();
            noOutEdgeNode.pop_back();
            for (auto k : invertedGraph[i]) {
                outEdgeNodeCount[k]--;
                if (outEdgeNodeCount[k] == 0) {
                    noOutEdgeNode.push_back(k);
                    ret.push_back(k);
                }
            }
        }
        sort(ret.begin(), ret.end());
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
    vector<int> retVec = solution.eventualSafeNodes(valueGrid);

    // output
    Output(retVec);

    return 0;
}

