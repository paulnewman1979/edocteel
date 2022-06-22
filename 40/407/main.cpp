#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[0] > b[0];
}

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int ret = 0, i, j, h, size1 = heightMap.size(), size2 = heightMap[0].size();
        vector<vector<int>> heightHeap;
        vector<vector<int>> mark(size1, vector<int>(size2, 0));
        for (i = 0; i < size1; ++i) {
            heightHeap.push_back(vector<int>{heightMap[i][0], i, 0});
            mark[i][0] = 1;
            heightHeap.push_back(vector<int>{heightMap[i][size2 - 1], i, size2 - 1});
            mark[i][size2 - 1] = 1;
        }
        for (j = 1; j < size2 - 1; ++j) {
            heightHeap.push_back(vector<int>{heightMap[0][j], 0, j});
            mark[0][j] = 1;
            heightHeap.push_back(vector<int>{heightMap[size1 - 1][j], size1 - 1, j});
            mark[size1 - 1][j] = 1;
        }
        make_heap(heightHeap.begin(), heightHeap.end(), compare);
        while (heightHeap.size() > 0) {
            pop_heap(heightHeap.begin(), heightHeap.end(), compare);
            vector<int> cur = heightHeap.back(); i = cur[1]; j = cur[2]; h = cur[0];
            heightHeap.pop_back();
            for (auto& d: dirs) {
                int ni = i + d[0], nj = j + d[1];
                if ((ni > 0) && (ni < size1 - 1) && (nj > 0) && (nj < size2 - 1) &&
                    (mark[ni][nj] == 0)) {
                    mark[ni][nj] = 1;
                    ret += max(0, h - heightMap[ni][nj]);
                    heightMap[ni][nj] = max(h, heightMap[ni][nj]);
                    heightHeap.push_back(vector<int>{heightMap[ni][nj], ni, nj});
                    push_heap(heightHeap.begin(), heightHeap.end(), compare);
                }
            }
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
    int ret = solution.trapRainWater(valueGrid);

    // output
    Output(ret);

    return 0;
}
