#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include <unordered_map>
#include <boost/algorithm/string.hpp>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string result;
        int maxCount = 0;
        string keyword;
        unordered_map<string, int> keywordMap;
        unordered_set<string> bannedKeyword;
        for (auto a : banned) bannedKeyword.insert(a);

        int i = 0, j = 0;
        for (j = 0; j < paragraph.size(); ++j) {
            if ((paragraph[j] <= 'z') && (paragraph[j] >= 'a')) {
            } else if ((paragraph[j] >= 'A') && (paragraph[j] <= 'Z')) {
                paragraph[j] -= 'A' - 'a';
            } else {
                if (j > i) {
                    keyword = paragraph.substr(i, j - i);
                    if (bannedKeyword.find(keyword) == bannedKeyword.end()) {
                        keywordMap[keyword]++;
                        if (keywordMap[keyword] > maxCount) {
                            result = keyword;
                            maxCount = keywordMap[keyword];
                        }
                    }
                }
                i = j + 1;
            }
        }
        if (j > i) {
            keyword = paragraph.substr(i, j - i);
            if (bannedKeyword.find(keyword) == bannedKeyword.end()) {
                keywordMap[keyword]++;
                if (keywordMap[keyword] > maxCount) {
                    result = keyword;
                    maxCount = keywordMap[keyword];
                }
            }
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    // input
    string paragraph;
    Input(paragraph);
    vector<string> banned;
    Input(banned);

    // solutionn
    Solution solution;
    string result = solution.mostCommonWord(paragraph, banned);

    // output
    Output(result);

    return 0;
}
