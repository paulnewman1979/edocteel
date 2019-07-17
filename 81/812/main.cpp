#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ret = 0.0, tmp;
        int i, j, k;
        for (i = 0; i < points.size(); ++i) {
            for (j = i + 1; j < points.size(); ++j) {
                for (k = j + 1; k < points.size(); ++k) {
                    tmp = points[i][1] * (points[k][0] - points[j][0]);
                    tmp += points[j][1] * (points[i][0] - points[k][0]);
                    tmp += points[k][1] * (points[j][0] - points[i][0]);
                    if (tmp > ret) {
                        ret = tmp;
                    } else if (-tmp > ret) {
                        ret = -tmp;
                    }
                }
            }
        }
        return ret/2;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    double ret = solution.largestTriangleArea(valueGrid);

    // output
    Output(ret);

    return 0;
}
