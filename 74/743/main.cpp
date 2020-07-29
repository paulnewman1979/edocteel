#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

struct Point {
    int index;
    int time;
    unordered_map<int, int> times;
    Point() { time = INT_MAX; }
};

bool compare(Point& a, Point& b) {
    return a.time > b.time;
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int ret = 0;
        vector<Point> points(N);
        for (int i = 0; i < N; ++i) {
            points[i].index = i;
        }
        for (auto time : times) {
            points[time[0] - 1].times[time[1] - 1] = time[2];
        }
        points[K - 1].time = 0;

        sort(points.begin(), points.end(), compare);
        while (points.size() > 0) {
            const Point& curPoint = points.back();
            if (curPoint.time == INT_MAX) return -1;
            ret = curPoint.time;
            //cout << "index=" << (curPoint.index + 1) << " time=" << curPoint.time << endl;
            for (auto& point : points) {
                unordered_map<int, int>::const_iterator iter = curPoint.times.find(point.index);
                if ((iter != curPoint.times.end()) &&
                        (curPoint.time + iter->second < point.time)) {
                    point.time = curPoint.time + iter->second;
                    //cout << "\tindex=" << (point.index + 1) << " time=" << point.time << endl;
                }
            }
            points.pop_back();
            sort(points.begin(), points.end(), compare);
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    int N, K;
    vector<vector<int>> valueGrid;
    Input(N);
    Input(K);
    Input(valueGrid);

    // solution
    Solution solution;
    int ret = solution.networkDelayTime(valueGrid, N, K);

    // output
    Output(ret);

    return 0;
}
