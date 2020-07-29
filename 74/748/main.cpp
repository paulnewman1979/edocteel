#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <iterator>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> count;
        unordered_map<char, int>::const_iterator iter;
        vector<int> wordCount(26, 0);
        int wordIndex = 0, length = 16;
        for (const auto& ch : licensePlate) {
            char c = tolower(ch);
            if (c >= 'a' && c <= 'z') {
                count[c]++;
            }
        }
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].length() < length) {
                fill(wordCount.begin(), wordCount.end(), 0);
                for (const auto& ch : words[i]) {
                    char c = tolower(ch);
                    wordCount[c - 'a']++;
                }
                iter = count.begin();
                while (iter != count.end()) {
                    if (wordCount[iter->first - 'a'] < iter->second) break;
                    ++iter;
                }
                if (iter == count.end()) {
                    length = words[i].length();
                    wordIndex = i;
                }
            }
        }
        return words[wordIndex];
    }
};

int main(int argc, char* argv[])
{
    // input
    string value;
    vector<string> valueVec;
    Input(value);
    Input(valueVec);

    // solution
    Solution solution;
    string ret = solution.shortestCompletingWord(value, valueVec);

    // output
    Output(ret);

    return 0;
}
