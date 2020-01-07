#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ret = 0, i, iCouple, iNeighborPos, iNeighbor;
        unordered_map<int, int> pos;
        for (i = 0; i < row.size(); i+=2) {
            pos[row[i]] = i;
            pos[row[i+1]] = i + 1;
        }
        for (i = 0; i < row.size(); i+=2) {
            iCouple = (row[i] % 2 == 0) ? row[i] + 1 : row[i] - 1;
            iNeighbor = row[i + 1];
            while (iNeighbor != iCouple) {
                ++ret;
                // get neighbor couple
                iNeighbor = (iNeighbor % 2 == 0) ? iNeighbor + 1 : iNeighbor - 1;
                // get neighbor couple's neighbor
                iNeighborPos = (pos[iNeighbor] % 2 == 0) ? pos[iNeighbor] + 1 : pos[iNeighbor] - 1;
                swap(row[i + 1], row[iNeighborPos]);
                iNeighbor = row[i + 1];
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.minSwapsCouples(valueVec);

    // output
    Output(ret);

    return 0;
}
