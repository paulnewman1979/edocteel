#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int ret = 0, i, j, k, l;
        vector<vector<int>> maxSum(2, vector<int>(s2.length() + 1, 0));
        for (i = 0; i < s1.length(); ++i) ret += s1[i];
        for (i = 0; i < s2.length(); ++i) ret += s2[i];
        k = 0;
        for (i = 0; i < s1.length(); ++i) {
            l = 1 - k;
            for (j = 0; j < s2.length(); ++j) {
                if (s2[j] == s1[i]) {
                    maxSum[l][j + 1] = maxSum[k][j] + s1[i];
                } else {
                    maxSum[l][j + 1] = max(maxSum[k][j + 1], maxSum[l][j]);
                }
            }
            k = 1 - k;
        }
        return (ret - maxSum[k][s2.length()] * 2);
    }
};

int main(int argc, char* argv[])
{
    // input
	string a;
	string b;
    Input(a);
    Input(b);

    // solution
    Solution solution;
    int ret = solution.minimumDeleteSum(a, b);

    // output
    Output(ret);

    return 0;
}
