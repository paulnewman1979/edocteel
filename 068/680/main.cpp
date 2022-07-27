#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int length = s.length();
        int i = 0, j = length - 1;
        while ((i < j) && (s[i] == s[j])) {
            ++i; --j;
        }
        if (i >= j) return true;

        int ni = i, nj = j - 1;
        while ((ni < nj) && (s[ni] == s[nj])) {
            ++ni; --nj;
        }
        if (ni >= nj) return true;

        ni = i + 1;
        nj = j;
        while ((ni < nj) && (s[ni] == s[nj])) {
            ++ni; --nj;
        }
        if (ni >= nj) return true;

        return false;
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	bool ret = solution.validPalindrome(str);

    // output
    Output(ret);

    return 0;
}
