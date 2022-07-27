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
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int ret = 0, m;
        int l1, l2;
        unordered_map<int, int> usedCharLocation;
        unordered_map<int, int>::const_iterator uIter;
        vector<vector<int>> charLocation(26);
        vector<int>::const_iterator iter;
        for (l1 = 0; l1 < s1.length(); ++l1) {
            charLocation[s1[l1] - 'a'].push_back(l1);
        }

        bool notFound = true;
        int t1 = 1, t2 = 0;
        l1 = -1;
        while ((notFound) && (t1 <= n1)) {
            ++t2;
            for (l2 = 0; l2 < s2.length(); ++l2) {
                const vector<int>& cur = charLocation[s2[l2] - 'a'];
                iter = upper_bound(cur.begin(), cur.end(), l1);
                if (iter == cur.end()) {
                    ++t1; if (t1 > n1) break;
                    iter = upper_bound(cur.begin(), cur.end(), -1);
                    if (iter == cur.end()) return 0;
                }
                l1 = *iter; m = (l1<<8) + l2;
                uIter = usedCharLocation.find(m);
                if (uIter != usedCharLocation.end()) {
                    m = uIter->second;
                    notFound = false;
                    break;
                } else {
                    usedCharLocation[m] = (t1<<8) + t2;
                }
            }
        }

        if (t1 > n1) return (t2 - 1) / n2;
        else {
            ret = (t2 - 1) + (n1 - t1) / (t1 - (m>>8)) * (t2 - (m&0xff));
            t1 = (n1 - t1) % (t1 - (m>>8)) + 1;

            while (t1 > 0) {
                for (++l2; l2 < s2.length(); ++l2) {
                    const vector<int>& cur = charLocation[s2[l2] - 'a'];
                    iter = upper_bound(cur.begin(), cur.end(), l1);
                    if (iter == cur.end()) {
                        --t1; if (t1 <= 0) break;
                        iter = upper_bound(cur.begin(), cur.end(), -1);
                    }
                    l1 = *iter;
                }
                if (l2 == s2.length()) {
                    ++ret;
                    l2 = -1;
                }
            }
        }

        return ret / n2;
    }
};

int main(int argc, char* argv[])
{
    // input
    int n1, n2;
	string s1, s2;
    Input(s1);
    Input(s2);
    Input(n1);
    Input(n2);

    // solution
    Solution solution;
    int ret = solution.getMaxRepetitions(s1, n1, s2, n2);

    // output
    Output(ret);

    return 0;
}
