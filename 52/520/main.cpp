#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int i;
        if (word.length() <= 1) return true;
        if ((word[0] >= 'A') && (word[0] <= 'Z')) {
            if ((word[1] >= 'A') && (word[1] <= 'Z')) {
                for (i = 2; i < word.length(); ++i) {
                    if ((word[i] < 'A') || (word[i] > 'Z')) return false;
                }
            } else {
                for (i = 2; i < word.length(); ++i) {
                    if ((word[i] < 'a') || (word[i] > 'z')) return false;
                }
            }
        } else {
            for (i = 1; i < word.length(); ++i) {
                if ((word[i] < 'a') || (word[i] > 'z')) return false;
            }
        }
        return true;
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	bool ret = solution.detectCapitalUse(str);

    // output
    Output(ret);

    return 0;
}
