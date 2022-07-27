#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size(), i, j, rootI, rootJ, provinceCount = size;
        vector<int> root(size);
        for (i = 0; i < size; ++i) {
            root[i] = i;
        }
        for (i = 0; i < size; ++i) {
            for (j = i + 1; j < size; ++j) {
                if (isConnected[i][j] == 1) {
                    rootI = i; while(rootI != root[rootI]) rootI = root[rootI];
                    rootJ = j; while(rootJ != root[rootJ]) rootJ = root[rootJ];
                    if (rootI < rootJ) {
                        root[rootJ] = rootI;
                        --provinceCount;
                    } else if (rootI > rootJ) {
                        root[rootI] = rootJ;
                        --provinceCount;
                    }
                }
            }
        }
        return provinceCount;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.findCircleNum(valueGrid);

    // output
    Output(ret);

    return 0;
}
