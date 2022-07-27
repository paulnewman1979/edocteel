#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
     bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        int gcf = getGCF(jug1Capacity, jug2Capacity);
        return (targetCapacity % gcf == 0);
    }

    int getGCF(int j1, int j2) {
        while ((j1 != 0) && (j2 != 0)) {
            if (j2 >= j1) {
                j2 %= j1;
            } else {
                j1 %= j2;
            }
        }
        return (j1 == 0) ? j2 : j1;
    }
};

int main(int argc, char* argv[])
{
    // input
    int j1, j2, tj;
    Input(j1);
    Input(j2);
    Input(tj);

    // solution
    Solution solution;
    bool ret = solution.canMeasureWater(j1, j2, tj);

    // output
    Output(ret);

    return 0;
}
