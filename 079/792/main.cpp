#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int i, j, chIndex, ret = 0;
        vector<vector<int>> next(S.length(), vector<int>(26, -1));
        for (i = 0; i < S.length(); ++i) {
            chIndex = S[i] - 'a';
            next[i][chIndex] = i;
            j = i - 1;
            while ((j >= 0) && (next[j][chIndex] == -1)) {
                next[j][chIndex] = i;
                --j;
            }
        }

        for (auto word : words) {
            i = 0;
            for (j = 0; j < word.length(); ++j) {
                i = next[i][word[j] - 'a'];
                if (i == -1) break;
                if ((i == S.length() - 1) && (j != word.length() - 1)) {
                    i = -1;
                    break;
                }
                ++i;
            }
            if (i != -1) {
                ++ret;
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    string S;
    vector<string> valueVec;
    Input(S);
    //Output(S);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.numMatchingSubseq(S, valueVec);

    // output
    Output(ret);

    return 0;
}
