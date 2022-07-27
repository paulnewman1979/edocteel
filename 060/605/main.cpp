#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, i = 0, size = flowerbed.size(), nCount = 0;
        while ((i < size) && (flowerbed[i] == 0)) {
            ++count;
            ++i;
        }
        if (i < size) {
            nCount += count / 2;
            count = 0;
            ++i;
            for (; i < size; ++i) {
                if (flowerbed[i] == 0) {
                    ++count;
                } else {
                    nCount += (count - 1) / 2;
                    count = 0;
                }
            }
            nCount += count / 2;
        } else {
            nCount += (count + 1) / 2;
        }

        return (nCount >= n);
    }
};

int main(int argc, char* argv[])
{
    // input
    int n;
    vector<int> valueVec;
    Input(n);
    Input(valueVec);

    // solution
    Solution solution;
    bool ret = solution.canPlaceFlowers(valueVec, n);

    // output
    Output(ret);

    return 0;
}
