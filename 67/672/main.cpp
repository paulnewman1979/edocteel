#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int flipLights(int n, int m) {
        if (m <= 0) return 1;
        int i, num = 0;
        unordered_set<int> possible;
        const vector<int> actions({0xff, 0x55, 0xaa, 0x9});
        n = (n > 5) ? 6 : n;
        m = (m > 4) ? ((m - 1) % 2 + 3) : m;
        for (i = 0; i < n; ++i) {
            num |= (1<<i);
        }
        mask = num;
        //cout << "num=" << num << endl;
        applyAction(num, actions, possible, 0, m);

		return possible.size();
    }

private:
    void applyAction(const int num,
            const vector<int>& actions,
            unordered_set<int>& possible,
            const int nIndex,
            const int m) {
        int newNum;
        for (int i = 0; i < actions.size(); ++i) {
            newNum = (num ^ actions[i]) & mask;
            std::bitset<8> newNumP(newNum);
            //cout << "nIndex=" << nIndex << "\tnewNum=" << newNumP << endl;
            if (nIndex + 1 == m) {
                possible.insert(newNum);
            } else {
                applyAction(newNum, actions, possible, nIndex + 1, m);
            }
        }
    }

    int mask;
};

int main(int argc, char* argv[])
{
    // input
    int sx, sy;
    Input(sx);
    Input(sy);

    // solution
    Solution solution;
    int ret = solution.flipLights(sx, sy);

    // output
    Output(ret);

    return 0;
}
