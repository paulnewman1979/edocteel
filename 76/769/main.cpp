#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int min = arr[0], max = arr[0];
        int start = 0, end;
        int ret = 0;
        for (end = 0; end < arr.size(); ++end) {
            if (max < arr[end]) max = arr[end];
            if (min > arr[end]) min = arr[end];
            if ((min == start) && (max == end)) {
                ++ret;
                start = end + 1;
                if (end + 1 < arr.size()) {
                    min = arr[end + 1];
                    max = arr[end + 1];
                }
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
    int ret = solution.maxChunksToSorted(valueVec);

    // output
    Output(ret);

    return 0;
}
