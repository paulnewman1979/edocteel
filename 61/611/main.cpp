#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int ret = 0, i, j, k, n1, n2, n3;
        vector<pair<int, int>> countNextVec(1001, pair(0, 0));
        for (i = 0; i < nums.size(); ++i) {
            countNextVec[nums[i]].first++;
        }
        j = -1;
        for (i = 1000; i >= 0; --i) {
            countNextVec[i].second = j;
            if (countNextVec[i].first > 0) j = i;
        }
        for (k = countNextVec[0].second; k != -1; k = countNextVec[k].second) {
            n1 = countNextVec[k].first;
            if (n1 > 2) ret += n1 * (n1 - 1) * (n1 - 2) / 6;
            //cout << endl << "n1=" << n1 << " ret=" << ret << endl;
            for (j = countNextVec[0].second; j < k; j = countNextVec[j].second) {
                n2 = countNextVec[j].first;
                if (n1 > 1) ret += n1 * (n1 - 1) / 2 * n2;
                if ((n2 > 1) && (j + j > k)) ret += n1 * n2 * (n2 - 1) / 2;
                //cout << "n2=" << n2 << " ret=" << ret << endl;
                i = max(countNextVec[j].second, k + 1 - j);
                //cout << "i=" << i << " j=" << j << " k=" << k << endl;
                for (; i < k; i = countNextVec[i].second) {
                    n3 = countNextVec[i].first;
                    ret += n1 * n2 * n3;
                    //cout << "n3=" << n3 << " ret=" << ret << endl;
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
    int ret = solution.triangleNumber(valueVec);

    // output
    Output(ret);

    return 0;
}
