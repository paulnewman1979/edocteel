#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ret = 0, i, j;
        vector<int> dp(B.size() + 1);
        for (i = A.size() - 1; i >= 0; --i) {
            for (j = 0; j < B.size(); ++j) {
                if (A[i] == B[j]) {
                    dp[j] = dp[j+1] + 1;
                    if (ret < dp[j]) ret = dp[j];
                } else {
                    dp[j] = 0;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> A;
    vector<int> B;
    Input(A);
    Input(B);

    // solution
    Solution solution;
    int ret = solution.findLength(A, B);

    // output
    Output(ret);

    return 0;
}
