#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while ((tx > sx) || (ty > sy)) {
            if (tx > ty) {
                tx -= max((tx - sx) / ty, 1) * ty;
            } else if (ty > tx) {
                ty -= max((ty - sy) / tx, 1) * tx;
            } else {
                return false;
            }
        }
        return ((tx == sx) && (ty == sy));
    }
};

int main(int argc, char* argv[])
{
    // input
    int sx, sy, tx, ty;
    Input(sx);
    Input(sy);
    Input(tx);
    Input(ty);

    // solution
    Solution solution;
    bool ret = solution.reachingPoints(sx, sy, tx, ty);

    // output
    Output(ret);

    return 0;
}
