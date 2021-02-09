#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;

		int ret = 0, step, p, q;
        static const int MOD = 1000000007;
        vector<vector<int>> count(m + 2, vector<int>(n + 2, 0));
        count[i + 1][j + 1] = 1;
        for (p = 1; p <= m; ++p) {
            count[p][0] = count[p][1];
            count[p][n + 1] = count[p][n];
        }
        for (q = 1; q <= n; ++q) {
            count[0][q] = count[1][q];
            count[m + 1][q] = count[m][q];
        }
        for (step = 1; step < N; ++step) {
            for (p = 1; p <= m; ++p) {
                for (q = 2 - (i + j + p + step) % 2 ; q <= n; q+=2) {
                    count[p][q] = 0;
                    count[p][q] += (p > 1) ? count[p - 1][q] : 0;
                    count[p][q] %= MOD;
                    count[p][q] += (p < m) ? count[p + 1][q] : 0;
                    count[p][q] %= MOD;
                    count[p][q] += (q > 1) ? count[p][q - 1] : 0;
                    count[p][q] %= MOD;
                    count[p][q] += (q < n) ? count[p][q + 1] : 0;
                    count[p][q] %= MOD;
                }
            }
            for (q = 2 - (i + j + step + 1) % 2; q <= n; q+=2) {
                count[0][q] += count[1][q];
                count[0][q] %= MOD;
            }
            for (q = 2 - (i + j + step + m) % 2; q <= n; q+=2) {
                count[m + 1][q] += count[m][q];
                count[m + 1][q] %= MOD;
            }
            for (p = 2 - (i + j + step + 1) % 2; p <= m; p+=2) {
                count[p][0] += count[p][1];
                count[p][0] %= MOD;
            }
            for (p = 2 - (i + j + step + n) % 2; p <= m; p+=2) {
                count[p][n + 1] += count[p][n];
                count[p][n + 1] %= MOD;
            }
            //cout << "step " << step << endl;
            //Output(count);
            //cout << endl;
        }

        ret = 0;
        for (p = 1; p <= m; ++p) {
            ret += count[p][0];
            ret %= MOD;
            ret += count[p][n + 1];
            ret %= MOD;
        }
        for (q = 1; q <= n; ++q) {
            ret += count[0][q];
            ret %= MOD;
            ret += count[m + 1][q];
            ret %= MOD;
        }

		return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int m, n, N, i, j;
    Input(m);
    Input(n);
    Input(N);
    Input(i);
    Input(j);

    // solution
    Solution solution;
    int ret = solution.findPaths(m, n, N, i, j);

    // output
    Output(ret);

    return 0;
}
