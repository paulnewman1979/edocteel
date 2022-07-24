#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int repeatSize, i, j, r = a % MOD;
        vector<int> rs;
        map<int, int> rPos;
        a = r; rs.push_back(0);
        map<int, int>::const_iterator iter = rPos.end();
        while (iter == rPos.end()) {
            rPos[r] = rs.size();
            rs.push_back(r);
            r = (r * a) % MOD;
            iter = rPos.find(r);
        }
        repeatSize = rs.size() - iter->second;
        if (b.size() <= 4) {
            j = 0;
            for (i = 0; i < b.size(); ++i) {
                j = j * 10 + b[i];
            }
            if (j >= rs.size()) {
                j %= repeatSize;
                while (j < iter->second) {
                    j += repeatSize;
                }
            }
        } else {
            j = 0;
            for (i = 0; i < b.size(); ++i) {
                j = j * 10 + b[i];
                j %= repeatSize;
            }
            while (j < iter->second) {
                j += repeatSize;
            }
        }
        return rs[j];
    }

private:
    static const int MOD = 1337;
};

int main(int argc, char* argv[])
{
    // input
    int value;
    vector<int> valueVec;
    Input(value);
    Input(valueVec);

    // solution
    Solution solution;
    int ret = solution.superPow(value, valueVec);

    // output
    Output(ret);

    return 0;
}
