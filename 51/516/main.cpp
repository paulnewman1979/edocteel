#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.length() == 0) return 0;
        int i, j, index = 0, prevIndex, size = s.length();
        vector<vector<int>> maxPal(2, vector<int>(size + 1, 0));
        for (j = size - 1; j > 0; --j) {
            maxPal[0][j] = (s[0] == s[j]) ? 2 : maxPal[0][j + 1];
        }
        maxPal[0][0] = max(1, maxPal[0][1]);
        for (i = 1; i < size - 1; ++i) {
            prevIndex = index;
            index = 1 - prevIndex;
            for (j = size - 1; j > i; --j) {
                if (s[i] == s[j]) {
                    maxPal[index][j] = maxPal[prevIndex][j + 1] + 2;
                } else {
                    maxPal[index][j] = max(maxPal[prevIndex][j], maxPal[index][j + 1]);
                }
                //cout << "(" << i << ", " << j << ")=" << maxPal[index][j] << endl;
            }
            maxPal[index][i] = max(maxPal[prevIndex][i + 1] + 1, maxPal[index][i + 1]);
            //cout << "(" << i << ", " << i << ")=" << maxPal[index][i] << endl << endl;
            maxPal[index][i - 1] = maxPal[prevIndex][i - 1];
        }
        j = 0;
        for (i = 0; i < size; ++i) {
            if (maxPal[index][i] > j) j = maxPal[index][i];
        }
        return j;
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	int ret = solution.longestPalindromeSubseq(str);

    // output
    Output(ret);

    return 0;
}
