#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() == 0) return word2.length();
        else if (word2.length() == 0) return word1.length();
        string& longWord = (word1.length() > word2.length()) ? word1 : word2;
        string& shortWord = (word1.length() > word2.length()) ? word2 : word1;
        vector<vector<int>> maxCommon(2, vector<int>(shortWord.length(), 1));

        int i = 0, j;
        while ((i < shortWord.length()) && (shortWord[i] != longWord[0])) {
            maxCommon[0][i] = 0;
            ++i;
        }
        int index = 0, prevIndex = 1;
        for (j = 1; j < longWord.length(); ++j) {
            prevIndex = index;
            index = 1 - index;
            if (maxCommon[prevIndex][0] > 0) {
                maxCommon[index][0] = maxCommon[prevIndex][0];
            } else {
                maxCommon[index][0] = (longWord[j] == shortWord[0]) ? 1 : 0;
            }
            for (i = 1; i < shortWord.length(); ++i) {
                if (shortWord[i] == longWord[j]) {
                    maxCommon[index][i] = maxCommon[prevIndex][i - 1] + 1;
                } else {
                    maxCommon[index][i] = max(maxCommon[prevIndex][i], maxCommon[index][i - 1]);
                }
            }
        }
        return (word1.length() + word2.length() - maxCommon[index][shortWord.length() - 1] * 2);
    }
};

int main(int argc, char* argv[])
{
    // input
	string a;
	string b;
    Input(a);
    Input(b);

    // solution
    Solution solution;
    int ret = solution.minDistance(a, b);

    // output
    Output(ret);

    return 0;
}
