#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int i, j, k;
        vector<int> line(123, 0);
        vector<string> lines({"qwertyuiop", "asdfghjkl", "zxcvbnm"});
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < lines[i].length(); ++j) {
                line[lines[i][j]] = i + 1;
                line[lines[i][j] - 'a' + 'A'] = i + 1;
            }
        }

        vector<string> ret;
        for (i = 0; i < words.size(); ++i) {
            k = line[words[i][0]];
            for (j = 1; j < words[i].length(); ++j) {
                if (line[words[i][j]] != k) break;
            }
            if (j == words[i].length()) ret.push_back(words[i]);
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    vector<string> ret = solution.findWords(valueVec);

    // output
    Output(ret);

    return 0;
}
