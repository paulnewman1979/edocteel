#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <sstream>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& words) {
        int i, j, value;
        unordered_map<string, int> domainNumMap;
        for (i = 0; i < words.size(); ++i) {
            value = 0;
            j = 0;
            while (words[i][j] != ' ') {
                value = value * 10 + (words[i][j] - '0');
                ++j;
            }
            ++j;
            domainNumMap[words[i].substr(j)] += value;
            while (j < words[i].length()) {
                if (words[i][j] == '.') {
                    domainNumMap[words[i].substr(j + 1)] += value;
                }
                ++j;
            }
        }

        vector<string> ret(domainNumMap.size());
        i = 0;
        for (const auto& p : domainNumMap) {
            ostringstream oss;
            oss << p.second << " " << p.first;
            ret[i] = oss.str();
            ++i;
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> words;
    Input(words);

    // solution
    Solution solution;
    vector<string> ret = solution.subdomainVisits(words);

    // output
    Output(ret);

    return 0;
}
