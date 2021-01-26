#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int len1, len2, len3;
        len1 = calLen(p1, p2);
        len2 = calLen(p1, p3);
        len3 = calLen(p1, p4);
        if ((len1 == 0) || (len2 == 0) || (len3 == 0)) return false;
        if (len1 == len2) {
            len2 = calLen(p4, p2);
            if (len2 != len1) return false;
            len2 = calLen(p4, p3);
            if (len2 != len1) return false;
            len2 = calLen(p2, p3);
            if (len2 != len3) return false;
        } else if (len1 == len3) {
            len3 = calLen(p2, p3);
            if (len3 != len1) return false;
            len3 = calLen(p4, p3);
            if (len3 != len1) return false;
            len3 = calLen(p2, p4);
            if (len3 != len2) return false;
        } else if (len2 == len3) {
            len3 = calLen(p2, p3);
            if (len3 != len2) return false;
            len3 = calLen(p2, p4);
            if (len3 != len2) return false;
            len3 = calLen(p3, p4);
            if (len3 != len1) return false;
        } else {
            return false;
        }
        return true;
    }

private:
    int calLen(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> p1, p2, p3, p4;
    Input(p1);
    Input(p2);
    Input(p3);
    Input(p4);

    // solution
    Solution solution;
    bool ret = solution.validSquare(p1, p2, p3, p4);

    // output
    Output(ret);

    return 0;
}
