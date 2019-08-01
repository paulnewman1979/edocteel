#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ret = 0;
        int i = 0, j = 0;
        int sCount = 0, wCount;
        char ch;
        vector<int> pos(words.size(), 0);
        while (i < S.length()) {
            ch = S[i];
            ++i;
            sCount = 1;
            while ((i < S.length()) && (S[i] == ch)) {
                ++i;
                ++sCount;
            }
            //cout << "sCount " << sCount << endl;
            for (j = 0; j < words.size(); ++j) {
                if (pos[j] != -1) {
                    wCount = 0;
                    while ((pos[j] < words[j].length()) && (words[j][pos[j]] == ch)) {
                        ++wCount;
                        ++pos[j];
                    } 
                    if ((wCount == 0) || (sCount < wCount) || ((sCount != wCount) && (sCount < 3))) {
                        pos[j] = -1;
                    }
                }
                //cout << j << " pos[j] " << pos[j] << endl;
            }
        }

        for (j = 0; j < words.size(); ++j) {
            if (pos[j] != -1) ++ret;
        }
        
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    string S;
    vector<string> valueVec;
    Input(S);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.expressiveWords(S, valueVec);

    // output
    Output(ret);

    return 0;
}
