#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() <= 3) return false;

        bool ret = false;
        bool larger = true;
        int left, right = 0, top, bottom, i, start;
        int leftLast, rightLast = 0, topLast, bottomLast = 0;
        topLast = top = x[0];
        leftLast = left = -x[1];
        bottom = x[0] - x[2];
        if (bottom >= 0) {
            larger = false;
            start = 3;
        } else {
            right = left + x[3];
            if (right > 0) {
                larger = true;
            } else {
                if (right == 0) top = bottomLast;
                larger = false;
            }
            start = 4;
        }

        i = start;
        while (larger && (i < x.size())) {
            switch(i % 4) {
              case 0:
                if (bottom + x[i] <= top) {
                    top = bottom + x[i];
                    larger = false;
                    if (top >= bottomLast) left = rightLast;
                    start = i + 1;
                } else {
                    topLast = top;
                    top = bottom + x[i];
                }
                break;
              case 1:
                if (right - x[i] >= left) {
                    left = right - x[i];
                    larger = false;
                    if (left <= rightLast) bottom = topLast;
                    start = i + 1;
                } else {
                    leftLast = left;
                    left = right - x[i];
                }
                break;
              case 2:
                if (top - x[i] >= bottom) {
                    bottom = top - x[i];
                    larger = false;
                    if (bottom < topLast) right = leftLast;
                    start = i + 1;
                } else {
                    bottomLast = bottom;
                    bottom = top - x[i];
                }
                break;
              default:
                if (left + x[i] <= right) {
                    right = left + x[i];
                    larger = false;
                    if (right >= leftLast) top = bottomLast;
                    start = i + 1;
                } else {
                    rightLast = right;
                    right = left + x[i];
                }
            }
            ++i;
        }

        if (!larger) {
            for (i = start; i < x.size(); ++i) {
                switch(i % 4) {
                  case 0:
                    if (bottom + x[i] >= top) return true;
                    else top = bottom + x[i];
                    break;
                  case 1:
                    if (right - x[i] <= left) return true;
                    else left = right - x[i];
                    break;
                  case 2:
                    if (top - x[i] <= bottom) return true;
                    else bottom = top - x[i];
                    break;
                  default:
                    if (left + x[i] >= right) return true;
                    else right = left + x[i];
                }
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<int> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    bool ret = solution.isSelfCrossing(valueVec);

    // output
    Output(ret);

    return 0;
}
