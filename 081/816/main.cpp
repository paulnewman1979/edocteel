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
    vector<string> ambiguousCoordinates(string S) {
        vector<string> results;
        for (size_t commaPos = 2; commaPos <= S.length() - 2; ++commaPos) {
            if (((commaPos != 2) &&(S[1] == '0') && (S[commaPos - 1] == '0')) ||
                    ((commaPos != (S.length() - 2)) && (S[commaPos] == '0') && (S[S.length() - 2] == '0'))) {
                continue;
            }
            vector<string> prefix;
            vector<string> postfix;
            expand(S, 1, commaPos, prefix);
            expand(S, commaPos, S.length() - 1, postfix);
            for (auto p : prefix) {
                for (auto q : postfix) {
                    results.push_back("(" + p + ", " + q + ")");
                }
            }
        }
        return results;
    }

private:
    void expand(string& S,
                 int start,
                 int end,
                 vector<string>& results) {
        if (end == start + 1) {
            results.push_back(S.substr(start, end - start));
        } else if (S[start] == '0') {
            results.push_back("0." + S.substr(start + 1, end - start - 1));
        } else if (S[end - 1] == '0') {
            results.push_back(S.substr(start, end - start));
        } else {
            results.push_back(S.substr(start, end - start));
            for (int dotPos = start + 1; dotPos < end; ++dotPos) {
                results.push_back(S.substr(start, dotPos - start) + "." + S.substr(dotPos, end - dotPos));
            }
        }
    }
};

int main(int argc, char* argv[])
{
    // innput
    string S;
    Input(S);

    // solution
    Solution solution;
    vector<string> ret = solution.ambiguousCoordinates(S);

    // output
    Output(ret);

    return 0;
}
