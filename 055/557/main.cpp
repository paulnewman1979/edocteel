#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i, j, k;
        string result(s);
        i = 0;
        for (j = 0; j < result.length(); ++j) {
            if (result[j] == ' ') {
                if (j - i > 1) {
                    k = j - 1;
                    while (i < k) {
                        swap(result[i], result[k]);
                        ++i;
                        --k;
                    }
                }
                i = j + 1;
            }
        }
        if (j - i > 1) {
            k = j - 1;
            while (i < k) {
                swap(result[i], result[k]);
                ++i;
                --k;
            }
        }
        return result;
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	string ret = solution.reverseWords(str);

    // output
    Output(ret);

    return 0;
}
