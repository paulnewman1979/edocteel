#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        if (1 == n) return 3;
        else if (2 == n) return 8;
        // ending with PP
        // ending with PLP
        // ending with PLLP
        static const int MOD = 1000000007;
        int i, ret;
        vector<unsigned long long int> P(n + 1);      // *P
        vector<unsigned long long int> PA(n + 1);     // *A*P
        vector<unsigned long long int> A(n + 1);      // *A

        //P[0] = 1; A[0] = 0; PA[0] = 0;
        P[1]  =  1;     // P
        A[1]  =  1;     // A
        PA[1] =  0;     //

        P[2]   = 2;     // PP LP
        A[2]   = 2;     // PA LA
        PA[2]  = 1;     // AP

        P[3]   = 4;     // PPP PLP LPP LLP
        A[3]   = 4;     // PPA PLA LLA LPA
        PA[3]  = 4;     // APP ALP LAP PAP

        for (i = 4; i <= n; ++i) {
            P[i] = (P[i - 1]            // *PP
                    + P[i - 2]          // *LP
                    + P[i - 3]) % MOD; // *LLP
            PA[i] = (A[i - 1]           // *AP
                    + PA[i - 1]         // *A*PP
                    + A[i - 2]         // *A*LP
                    + PA[i - 2]
                    + A[i - 3]
                    + PA[i - 3]) % MOD;// *A*LLP
            A[i] = (P[i - 1]            // *PA
                    + P[i - 2]          // *LA
                    + P[i - 3]) % MOD; // *LLA
        }
        ret = (P[n] + PA[n] + A[n] + P[n - 1] + A[n - 1] + PA[n - 1] + P[n - 2] + A[n -2] + PA[n - 2]) % MOD;
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int K;
    Input(K);

    // solution
    Solution solution;
    int ret = solution.checkRecord(K);

    // output
    Output(ret);

    return 0;
}
