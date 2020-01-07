#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> results;
        vector<int> posRange(256, 0);
        int i, startPos = 0, maxPos = 0;
        for (i = 0; i < S.length(); ++i) {
            if (i > posRange[S[i]]) {
                posRange[S[i]] = i;
            }
        }
        for (i = 0; i < S.length(); ++i) {
            if (posRange[S[i]] > maxPos) maxPos = posRange[S[i]];
            if (i == maxPos) {
                results.push_back(i - startPos + 1);
                startPos = i + 1;
            }
        }
        return results;
    }
};

int main(int argc, char* argv[])
{
    // input
    string S;
    Input(S);

    // solution
    Solution solution;
    vector<int> ret = solution.partitionLabels(S);

    // output
    Output(ret);

    return 0;
}
