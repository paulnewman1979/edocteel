#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int size = machines.size(), i, max = 0, avg, needed;
        for (i = 0; i < size; ++i) {
            max += machines[i];
        }
        if (max % size != 0) return -1;
        avg = max / size;
        needed = 0;
        max = 0;
        for (i = 0; i < size; ++i) {
            if (machines[i] >= avg) {
                if (needed >= 0) {
                    if (machines[i] - avg > max) max = machines[i] - avg;
                } else if (machines[i] - needed - avg > max) {
                    max = machines[i] - needed - avg;
                }
            } else {
                if (needed > 0) {
                    if (needed + avg - machines[i] > max) max = needed + avg - machines[i];
                } else {
                    if (avg - machines[i] + needed > max) {
                        max = avg - machines[i] + needed;
                    }
                    if (-needed > max) max = -needed;
                }
            }
            needed += avg - machines[i];
        }

        return max;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.findMinMoves(valueVec);

    // output
    Output(ret);

    return 0;
}
