#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& values, string pattern) {
        unordered_map<char, char> valueMap;
        unordered_map<char, char> patternMap;
        unordered_map<char, char>::const_iterator iter;
        vector<string> result;
        int i, j;
        for (i = 0; i < values.size(); ++i) {
            if (values[i].length() != pattern.length()) {
                continue;
            }

            valueMap.clear();
            patternMap.clear();
            for (j = 0; j < pattern.length(); ++j) {
                iter = valueMap.find(values[i][j]);
                if (iter == valueMap.end()) {
                    valueMap[values[i][j]] = pattern[j];
                } else if (iter->second != pattern[j]) {
                    break;
                }

                iter = patternMap.find(pattern[j]);
                if (iter == patternMap.end()) {
                    patternMap[pattern[j]] = values[i][j];
                } else if (iter->second != values[i][j]) {
                    break;
                }
            }
            if (j == pattern.length()) {
                result.push_back(values[i]);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    string pattern;
    vector<string> values;
    vector<string> result;
    string value;

    cin >> pattern;
    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    result = solution.findAndReplacePattern(values, pattern);
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
