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
    vector<string> letterCasePermutation(string S) {
        vector<string> results;
        vector<string> tmp;
        results.push_back(S);
        int size, i, j;
        for (i = 0; i < S.length(); ++i) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                size = results.size();
                for (j = 0; j < size; ++j) {
                    results.push_back(results[j]);
                    results.back()[i] = (results[j][i] + 'A' - 'a');
                }
            } else if (S[i] >= 'A' && S[i] <= 'Z') {
                size = results.size();
                for (j = 0; j < size; ++j) {
                    results.push_back(results[j]);
                    results.back()[i] = (results[j][i] + 'a' - 'A');
                }
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
    vector<string> ret = solution.letterCasePermutation(S);

    // output
    Output(ret);

    return 0;
}
