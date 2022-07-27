#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int curM = m, curN = n;
        for (auto& op : ops) {
            if (op[0] < curM) curM = op[0];
            if (op[1] < curN) curN = op[1];
        }
        return curM * curN;
    }
};

int main(int argc, char* argv[])
{
    // input
    int m, n;
    vector<vector<int>> valueGrid;
    Input(m);
    Input(n);
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.maxCount(m, n, valueGrid);

    // output
    Output(ret);

    return 0;
}
