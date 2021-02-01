#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int i = 0, maxLength = -1, len;
        unordered_map<string, int> strCount;
        for (i = 0; i < strs.size(); ++i) {
            strCount[strs[i]]++;
        }
        unordered_map<string, int>::const_iterator iter = strCount.begin();
        unordered_map<string, int>::const_iterator iter1;
        while (iter != strCount.end()) {
            len = iter->first.length();
            if ((iter->second == 1) && (len > maxLength)) {
                iter1 = strCount.begin();
                while (iter1 != strCount.end()) {
                    if ((iter1->first.length() >= len) &&
                            (iter1->first != iter->first)) {
                        if (checkSub(iter1->first, iter->first)) break;
                    }
                    ++iter1;
                }
                if (iter1 == strCount.end()) {
                    maxLength = len;
                }
            }
            ++iter;
        }
        return maxLength;
    }

private:
    bool checkSub(const string& a, const string& b) {
        int i = 0, j = 0;
        for (i = 0; i < b.length(); ++i) {
            while ((j < a.length()) && (a[j] != b[i])) ++j;
            if (j == a.length()) {
                return false;
            } else {
                ++j;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.findLUSlength(valueVec);

    // output
    Output(ret);

    return 0;
}
