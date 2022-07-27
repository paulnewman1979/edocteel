#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int i;
        vector<int> S(A.size()), N(A.size());
        S[0] = 1;
        N[0] = 0;
        for (i = 1; i < A.size(); ++i) {
            if ((A[i] <= A[i - 1]) || (B[i] <= B[i - 1])) {
                S[i] = N[i - 1] + 1;
                N[i] = S[i - 1];
            } else if ((A[i] <= B[i - 1]) || (B[i] <= A[i - 1])) {
                S[i] = S[i - 1] + 1;
                N[i] = N[i - 1];
            } else {
                N[i] = min(S[i - 1], N[i - 1]);
                S[i] = N[i - 1] + 1;
            }
        }
        return min(S[A.size() - 1], N[A.size() - 1]);
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
    int ret = solution.minSwap(A, B);

    // output
    Output(ret);

    return 0;
}
