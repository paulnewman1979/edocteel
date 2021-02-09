#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        if (n.size() == 1) {
            n[0] = n[0] - 1;
            return n;
        }
        _n = n;
        size = n.length(); lvr = 0; lv = 0; rv = 0;
        hv1 = 1; hv2 = 0;
        int i = (size - 1) / 2, j = size / 2, k = 0;
        int diff1, diff2, diff3;
        while (i >= 0) {
            lvr = lvr * 10 + (n[i] - '0');
            rv = rv * 10 + (n[j] - '0');
            lv = lv * 10 + (n[k] - '0');
            hv1 = hv1 * 10;
            hv2 = hv2 * 10 + 9;
            --i;
            ++j;
            ++k;
        }
        hv1 /= 10;

        diff2 = lvr - rv;
        if (diff2 > 0) {
            intToString(lv, ret2);
            diff1 = getLowerDiff();
            return (diff1 <= diff2) ? ret1 : ret2;
        } else if (diff2 < 0) {
            intToString(lv, ret2);
            diff3 = getHigherDiff();
            return (-diff2 <= diff3) ? ret2 : ret3;
        } else {
            diff1 = getLowerDiff();
            diff3 = getHigherDiff();
            return (diff1 <= diff3) ? ret1 : ret3;
        }
	}

private:
    int getHigherDiff() {
        if (lv == hv2) {
            ret3.resize(size + 1, '0');
            ret3[0] = '1';
            ret3[size] = '1';
            return 2;
        } else {
            intToString(lv + 1, ret3);
            return getStringDiff(_n, ret3);
        }
    }

    int getLowerDiff() {
        if (lv == hv1) {
            ret1.resize(size - 1, '9');
            return (_n[size - 1] == '0') ? 1 : 2;
        } else {
            intToString(lv - 1, ret1);
            return getStringDiff(ret1, _n);
        }
    }

    void intToString(int value, string& ret) {
        int i, j;
        ret.resize(size);
        if (size % 2 == 0) {
            for (i = size / 2 - 1, j = i + 1; i >= 0; --i, ++j) {
                ret[i] = ret[j] = '0' + (value % 10);
                value = value / 10;
            }
        } else {
            i = size / 2; j = i + 1;
            ret[i] = '0' + (value % 10);
            value /= 10;
            --i;
            for (; i >= 0; --i, ++j) {
                ret[i] = ret[j] = '0' + (value % 10);
                value = value / 10;
            }
        }
    }

    int getStringDiff(string& ret1, string& ret2) {
        int diff = 0, i = 0;
        for (i = 0; i < size; ++i) {
            diff = diff * 10 + ret2[i] - ret1[i];
        }
        return diff;
    }

private:
    int size;
    int lv;
    int rv;
    int lvr;
    int hv1;
    int hv2;
    string ret1;
    string ret2;
    string ret3;
    string _n;
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	string ret = solution.nearestPalindromic(str);

    // output
    Output(ret);

    return 0;
}
