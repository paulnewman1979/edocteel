#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int size = courses.size(), i, cur = 0;
        priority_queue<int> heap;
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>&b) {return a[1] < b[1];});
        for (i = 0; i < size; ++i) {
            heap.push(courses[i][0]);
            cur += courses[i][0];
            if (cur > courses[i][1]) {
                cur -= heap.top();
                heap.pop();
            }
        }
        return heap.size();
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.scheduleCourse(valueGrid);

    // output
    Output(ret);

    return 0;
}
