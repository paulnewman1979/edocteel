#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    Solution(vector<vector<int>>& rects): _rects(rects) {
        sum = 0;
        sums.push_back(sum);
        for (const auto& rect : rects) {
            sum += (rect[2] + 1 - rect[0]) * (rect[3] + 1 - rect[1]);
            sums.push_back(sum);
        }
        //Output(sums);
        //cout << endl << endl;
    }
            
    vector<int> pick() {
        vector<int> point(2, 0);
        int rd = rand() % sum;
        vector<int>::iterator iter = lower_bound(sums.begin(), sums.end(), rd);
        int idx = iter - sums.begin() - 1;
        //cout << "rd = " << rd << ", idx = " << idx << endl;
        rd -= sums[idx];
        //cout << "rd = " << rd << endl;
        point[0] = rd / (_rects[idx][3] - _rects[idx][1]) + _rects[idx][0];
        point[1] = rd % (_rects[idx][3] - _rects[idx][1]) + _rects[idx][1];
        return point;
    }

private:
    const vector<vector<int>>& _rects;
    vector<int> sums;
    int sum;
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution(valueGrid);
    for (int i = 0; i < 10; ++i) {
        vector<int> point = solution.pick();
        cout << "(" << point[0] << ", " << point[1] << ")" << endl;
    }

    return 0;
}
