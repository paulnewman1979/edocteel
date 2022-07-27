#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ret = 0;
        vector<int> count(MAX_NUM + 1, 0);
        for (auto i : nums) {
            count[i]++;
        }
        int maxHasI = 0, maxNoI= 0;
        int tmp = 0;
        for (int i = 1; i <= MAX_NUM; ++i) {
            if (count[i] == 0) {
                if (maxHasI > maxNoI) ret += maxHasI; else ret += maxNoI;
                maxHasI = 0;
                maxNoI = 0;
            } else {
                tmp = maxHasI;
                maxHasI = maxNoI + count[i] * i;
                maxNoI = (tmp > maxNoI) ? tmp : maxNoI;
            }
        }
        ret += (maxHasI > maxNoI) ? maxHasI : maxNoI;
        return ret;
    }

private:
    const static int MAX_NUM = 10000;
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.deleteAndEarn(valueVec);

    // output
    Output(ret);

    return 0;
}
