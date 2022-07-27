#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        _count = 0;
        _n = n;
        int i, j;
        vector<vector<int>> pp(_n + 1);
        vector<int> poses(_n + 1, 0);
        for (i = 1; i <= _n; ++i) {
            for (j = 1; j <= _n; ++j) {
                if ((i % j == 0) || (j % i == 0)) {
                    pp[i].push_back(j);
                }
            }
        }

        checkNum(pp, 1, poses);
        return _count;
    }

private:
    void checkNum(const vector<vector<int>>& pp,
        int i,
        vector<int>& poses) {
        for (auto& p : pp[i]) {
            if (poses[p] == 0) {
                if (i == _n) {
                    ++_count;
                } else {
                    poses[p] = 1;
                    checkNum(pp, i + 1, poses);
                    poses[p] = 0;
                }
            }
        }
    }

private:
    int _count;
    int _n;
};

int main(int argc, char* argv[])
{
    // input
    int K;
    Input(K);

    // solution
    Solution solution;
    int ret = solution.countArrangement(K);

    // output
    Output(ret);

    return 0;
}
