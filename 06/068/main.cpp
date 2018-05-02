#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i, j, k;
        std::string curLine;
        int blankSpace;
        i = 0;
        while (i < words.size()) {
            blankSpace = maxWidth - words[i].length();
            j = i + 1;
            while ((j < words.size()) &&
                    (blankSpace >= 1 + words[j].length())) {
                blankSpace -= 1 + words[j].length();
                ++j;
            }

            if (j == words.size()) {
                curLine = words[i];
                for (k = i + 1; k < j; ++k) {
                    curLine.append(" ");
                    curLine.append(words[k]);
                }
                curLine.append(std::string(maxWidth - curLine.length(), ' '));
                result.push_back(curLine);
            } else if (j - i == 1) {
                curLine = words[i];
                if (words[i].length() < maxWidth) {
                    curLine.append(std::string(maxWidth - words[i].length(), ' '));
                }
                result.push_back(curLine);
            } else {
                int avgBlank = blankSpace / (j - i - 1) + 1;
                int moreBlank = blankSpace - (avgBlank - 1) * (j - i - 1);
                curLine = words[i];
                for (k = 1; k < j - i; k++) {
                    if (k <= moreBlank) {
                        curLine.append(std::string(avgBlank + 1, ' '));
                    } else {
                        curLine.append(std::string(avgBlank, ' '));
                    }
                    curLine.append(words[i + k]);
                }
                result.push_back(curLine);
            }
            i = j;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    int maxWidth;
    vector<string> words;
    vector<string> result;
    string word;

    cin >> maxWidth;
    cin >> n;
    while (n > 0) {
        cin >> word;
        words.push_back(word);
        --n;
    }
        
    Solution solution;
    result = solution.fullJustify(words, maxWidth);
    for (int i=0; i<result.size(); ++i) {
        cout << "\"" << result[i] << "\"" << endl;
    }

    return 0;
}
