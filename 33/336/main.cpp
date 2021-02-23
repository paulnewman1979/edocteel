#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        static const int MAX_LENGTH = 300;
        vector<vector<int>> lenIndex(MAX_LENGTH + 1);
        int i, p, q, size = words.size();
        for (i = 0; i < size; ++i) {
            lenIndex[words[i].length()].push_back(i);
        }
        vector<pair<int, int>> innerP;
        unordered_map<string, vector<int>> rvWordMap;
        unordered_map<string, vector<int>>::iterator iter;
        for (auto& idx : lenIndex[0]) rvWordMap[""].push_back(idx);
        for (i = 1; i <= MAX_LENGTH; ++i) {
            for (auto& idx : lenIndex[i]) {
                const string& word = words[idx];
                innerP.clear();
                for (p = 0; p < word.length() - 1; ++p) {
                    for (q = 1; (q <= p) && (q < word.length() - p); ++q)
                        if (word[p - q] != word[p + q]) break;
                    if (q == p + 1) {
                        innerP.push_back(pair(0, p + p));
                    } else if (p + q == word.length()) {
                        innerP.push_back(pair(p - q + 1, word.length() - 1));
                    }

                    for (q = 0; (q <= p) && (q < word.length() - p - 1); ++q) {
                        if (word[p - q] != word[p + q + 1]) break;
                    }
                    if (q == p + 1) {
                        innerP.push_back(pair(0, p + p + 1));
                    } else if (p + q + 1 == word.length()) {
                        innerP.push_back(pair(p - q + 1, word.length() - 1));
                    }
                }
                innerP.push_back(pair(p, p));
                innerP.push_back(pair(0, -1));
                innerP.push_back(pair(word.length(), word.length() - 1));

                for (auto& k : innerP) {
                    if (k.first == 0) {
                        iter = rvWordMap.find(word.substr(k.second + 1));
                        if (iter != rvWordMap.end()) {
                            for (auto& v : iter->second) {
                                ret.push_back(vector<int>({v, idx}));
                            }
                        }
                    }
                    if (k.second == word.length() - 1) {
                        iter = rvWordMap.find(word.substr(0, k.first));
                        if (iter != rvWordMap.end()) {
                            for (auto& v : iter->second) {
                                ret.push_back(vector<int>({idx, v}));
                            }
                        }
                    }
                }
                rvWordMap[reverseStr(word)].push_back(idx);
            }
        }
        return ret;
    }

private:
    string reverseStr(const string& str) {
        string newStr = str;
        int i = 0, j = str.length() - 1;
        while (i < j) {
            swap(newStr[i], newStr[j]);
            ++i;
            --j;
        }
        return newStr;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> nums;
    Input(nums);

    // solution
    Solution solution;
    vector<vector<int>> ret = solution.palindromePairs(nums);

    // output
    Output(ret);

    return 0;
}
