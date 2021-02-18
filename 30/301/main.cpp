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
    vector<string> removeInvalidParentheses(string s) {
        vector<string> results;
        if (s.length() == 0) {
            results.push_back("");
            return results;
        }
        int count, i = 0, j, pidx = 0, sidx = 0, len = s.length();
        bool first;
        string newS;
        vector<vector<pair<int, string>>> prefix(2);
        vector<vector<pair<int, string>>> suffix(2);
        i = 0;
        while ((i < len) && (s[i] != '(') && (s[i] != ')')) ++i;
        if (i == len) {
            results.push_back(s);
            return results;
        }

        if (s[i] == ')') {
            prefix[0].push_back(pair(i, (i > 0) ? s.substr(0, i) : ""));
            count = 0;
        } else {
            prefix[0].push_back(pair(-1, ""));
            count = 1;
        }
        for (i = i + 1; i < len; ++i) {
            if (s[i] == '(') {
                ++count;
            } else if (s[i] == ')') {
                if (count == 0) {
                    pidx = 1 - pidx;
                    prefix[pidx].clear();
                    for (auto& p : prefix[1 - pidx]) {
                        first = true;
                        for (j = p.first + 1; j <= i; ++j) {
                            if (s[j] == ')') {
                                if (first) {
                                    prefix[pidx].push_back(pair(j, 
                                                ((j > p.first + 1) ?
                                                 (p.second + s.substr(p.first + 1, j - p.first - 1)) :
                                                 p.second)
                                                ));
                                    first = false;
                                }
                            } else {
                                first = true;
                            }
                        }
                    }
                } else {
                    --count;
                }
            }
        }

        if (count > 0) {
            i = len - 1;
            while ((i >= 0) && (s[i] != ')') && (s[i] != '(')) --i;
            if (s[i] == '(') {
                suffix[sidx].push_back(pair(i, (i < len - 1) ? s.substr(i + 1) : ""));
                count = 0;
            } else {
                suffix[sidx].push_back(pair(len, ""));
                count = 1;
            }
            for (i = i - 1; i >= 0; --i) {
                if (s[i] == ')') {
                    ++count;
                } else if (s[i] == '(') {
                    if (count == 0) {
                        sidx = 1 - sidx;
                        suffix[sidx].clear();
                        for (auto& p : suffix[1 - sidx]) {
                            first = true;
                            for (j = p.first - 1; j >= i; --j) {
                                if (s[j] == '(') {
                                    if (first) {
                                        suffix[sidx].push_back(pair(j, 
                                                    ((j < p.first - 1) ?
                                                     (s.substr(j + 1, p.first - j - 1)) + p.second :
                                                     p.second)
                                                    ));
                                        first = false;
                                    }
                                } else {
                                    first = true;
                                }
                            }
                        }
                    } else {
                        --count;
                    }
                }
            }
        } else {
            suffix[0].push_back(pair(len, ""));
        }

        for (auto& p : prefix[pidx]) {
            for (auto& q : suffix[sidx]) {
                if (q.first > p.first + 1) {
                    newS = p.second + s.substr(p.first + 1, q.first - p.first - 1) + q.second;
                } else {
                    newS = p.second + q.second;
                }
                results.push_back(newS);
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
    vector<string> ret = solution.removeInvalidParentheses(S);

    // output
    Output(ret);

    return 0;
}
