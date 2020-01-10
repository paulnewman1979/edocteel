#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return (a[0] < b[0]);
}

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int ret = 0, i, j;
        vector<int> count(intervals.size(), 0);
        vector<vector<int>> point(intervals.size() * 2, vector<int>(2, 0));
        vector<int> toadd;
        unordered_set<int> scope;

        for (i = 0; i < intervals.size(); ++i) {
            point[i + i][0] = intervals[i][0];
            point[i + i][1] = i;
            point[i + i + 1 ][0] = intervals[i][1];
            point[i + i + 1 ][1] = i;
        }
        sort(point.begin(), point.end(), compare);

        int cur = point[0][0], minCount = 2;
        for (i = 0; i < point.size(); ++i) {
            if (cur != point[i][0] ) {
                switch(minCount) {
                case 0:
                    ret += 2;
                    for (auto& c : toadd) count[c]++;
                    for (auto& c : scope) count[c]+=2;
                    break;
                case 1:
                    ++ret;
                    for (auto& c : toadd) count[c]++;
                    for (auto& c : scope) count[c]++;
                    break;
                default:
                    break;
                }
                for (auto& c : toadd) scope.insert(c);
                toadd.clear();
                minCount = 2;
                cur = point[i][0];
            }
            
            j = point[i][1];
            if (cur == intervals[j][0]) {
                toadd.push_back(j);
            } else {
                if (count[j] < minCount) minCount = count[j];
                scope.erase(j);
            }
        }
        while (scope.size() > 0) {
            for (auto& c : scope) {
                if (count[c] < minCount) minCount = count[c];
            }
        }
        if (minCount > 2) minCount = 2;
        ret += 2 - minCount;

        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);
    //Output(valueGrid);

    // solution
    Solution solution;
    int ret = solution.intersectionSizeTwo(valueGrid);

    // output
    Output(ret);

    return 0;
}
