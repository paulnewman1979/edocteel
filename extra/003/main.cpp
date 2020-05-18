#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ret = 0, size = A.size();
        vector<int>::iterator low, up, iter;
        vector<int> sums(size + 1, 0);
        for (int i = 0; i < size; ++i) {
            sums[i + 1] = sums[i] + A[i];
        }
        for (iter = sums.begin(); iter != sums.end(); ++iter) {
            low = lower_bound(iter, sums.end(), (*iter) + L);
            up = upper_bound(iter, sums.end(), (*iter) + R);
            if (low != sums.end()) {
                ret += up - low;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int L, R;
    vector<int> valueVec;
    Input(valueVec);
    Input(L);
    Input(R);

    // solution
    Solution solution;
    int ret = solution.numSubarrayBoundedMax(valueVec, L, R);

    // output
    Output(ret);

    return 0;
}
