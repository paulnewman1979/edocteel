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
    int maxChunksToSorted(vector<int>& arr) {
        int ret = 0;
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> posRange;
        posRange[sortedArr[0]] = 0;
        for (int i = 1; i < sortedArr.size(); ++i) {
            if (sortedArr[i] != sortedArr[i - 1]) {
                posRange[sortedArr[i]] = i;
            }
        }

        int max = -1, maxCount = 0, count = 0;
        for (auto v : arr) {
            if (max < v) {
                count += maxCount;
                maxCount = 1;
                max = v;
            } else if (max == v) ++maxCount;
            else ++count;

            if (count == posRange[max]) ++ret;
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
