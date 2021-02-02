#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        if (1 == k) return s;
        unsigned long i = 0, j, l, m;
        while (i < s.length()) {
            j = min(i + k, s.length()) - 1;
            l = i; m = j;
            while (l < m) {
                swap(s[l], s[m]);
                ++l;
                --m;
            }
            i += k + k;
        }
        return s;
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    int k;
    Input(str);
    Input(k);

    // solution
    Solution solution;
	string ret = solution.reverseStr(str, k);

    // output
    Output(ret);

    return 0;
}
