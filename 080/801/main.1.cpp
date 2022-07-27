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
        int i, S = 1, N = 0, tmp;
        for (i = 1; i < A.size(); ++i) {
            if ((A[i] <= A[i - 1]) || (B[i] <= B[i - 1])) {
                tmp = N + 1;
                N = S;
                S = tmp;
            } else if ((A[i] <= B[i - 1]) || (B[i] <= A[i - 1])) {
                S = S + 1;
            } else {
                N = min(S, N);
                S = N + 1;
            }
        }
        return min(S, N);
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
