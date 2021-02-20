#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b) {
    return ((a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1])));
}

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int pos, left, top, bottom;
        left = rectangles[0][0];
        bottom = rectangles[0][1];
        top = rectangles[0][3];
        for (vector<int>& rec : rectangles) {
            if (left > rec[0]) left = rec[0];
            if (bottom > rec[1]) bottom = rec[1];
            if (top < rec[3]) top = rec[3];
        }
        sort(rectangles.begin(), rectangles.end(), comp);
        vector<vector<int>> range;
        vector<vector<int>>::iterator iter;
        range.push_back(vector({left, bottom, top}));
        vector<int> cr(3);
        for (vector<int>& rec : rectangles) {
            if ((rec[0] != range[0][0]) ||
                    (rec[1] != range[0][1])) {
                return false;
            } else if (rec[3] > range[0][2]) {
                return false;
            } else {
                if (rec[3] < range[0][2]) range[0][1] = rec[3];
                else range.erase(range.begin());
                cr[0] = rec[2]; cr[1] = rec[1]; cr[2] = rec[3];
                iter = lower_bound(range.begin(), range.end(), cr, comp);
                if (iter == range.end()) pos = range.size();
                else pos = iter - range.begin();
                if ((pos < range.size()) &&
                        (range[pos][0] == rec[2]) &&
                        (range[pos][1] == rec[3])) {
                    if ((pos > 0) &&
                            (range[pos - 1][0] == rec[2]) &&
                            (range[pos - 1][2] == rec[1])) {
                        range[pos - 1][2] = range[pos][2];
                        range.erase(iter);
                    } else {
                        range[pos][1] = rec[1];
                    }
                } else if ((pos > 0) &&
                        (range[pos - 1][0] == rec[2]) &&
                        (range[pos - 1][2] == rec[1])) {
                    range[pos - 1][2] = rec[3];
                } else {
                    range.insert(iter, cr);
                }
            }
        }

        return ((range.size() == 1) && (range[0][1] == bottom) && (range[0][2] == top));
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    bool ret = solution.isRectangleCover(valueGrid);

    // output
    Output(ret);

    return 0;
}
