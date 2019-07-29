#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> ret(2, 0);
        ret[0] = 1;
        for (char ch : S) {
            if (ret[1] + widths[ch - 'a'] > 100) {
                ret[0]++;
                ret[1] = widths[ch - 'a'];
            } else {
                ret[1] += widths[ch - 'a'];
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    string S;
    vector<int> values;
    Input(S);
    Input(values);

    // solution
    Solution solution;
    vector<int> ret = solution.numberOfLines(values, S);

    // output
    Output(ret);

    return 0;
}
