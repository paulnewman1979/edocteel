#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <utility>

using namespace std;

static long long int MODULO = 1000000007LL;

bool Compare1(pair<int, int>& a, pair<int, int>& b) {
    return (a.first < b.first);
}

typedef pair<int, pair<int, int> > XY;

bool Compare2(XY& a, XY& b) {
    return (a.second.first < b.second.first) ||
        ((a.second.first == b.second.first) &&
         (a.second.second < b.second.second));
}

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        long long int area = 0;
        vector<pair<int, int> > lines;
        int i;
        for (i = 0; i < rectangles.size(); ++i) {
            lines.push_back(make_pair(rectangles[i][0], i));
            lines.push_back(make_pair(rectangles[i][2], i));
        }
        sort(lines.begin(), lines.end(), Compare1);

        int X = lines[0].first;
        i = 0;
        int index;
        vector<pair<int, pair<int, int>>> ylines;
        vector<pair<int, pair<int, int>>> ylinesTmp;
        while ((i < lines.size()) &&
                (lines[i].first == X)) {
            index = lines[i].second;
            ylines.push_back(make_pair(rectangles[index][2], make_pair(rectangles[index][1], rectangles[index][3])));
            ++i;
        }
        long long int ylength = computeLength(ylines);

        while (i < lines.size()) {
            area += ylength * (lines[i].first - X);
            area %= MODULO;
            X = lines[i].first;
            ylinesTmp.clear();
            for (auto x: ylines) {
                if (x.first != X) ylinesTmp.push_back(x);
            }
            ylines.swap(ylinesTmp);
            while ((i < lines.size()) &&
                    (lines[i].first == X)) {
                index = lines[i].second;
                if (rectangles[index][0] == X) {
                    ylines.push_back(make_pair(rectangles[index][2], make_pair(rectangles[index][1], rectangles[index][3])));
                }
                ++i;
            }
            ylength = computeLength(ylines);
        }

        return area;
    }

private:
    long long int computeLength(vector<pair<int, pair<int, int>>>& ylines) {
        if (ylines.size() == 0) return 0;

        long long int ylength = 0;
        sort(ylines.begin(), ylines.end(), Compare2);
        int start = ylines[0].second.first;
        int end = ylines[0].second.second;
        for (int i = 1; i < ylines.size(); ++i) {
            if (ylines[i].second.first > end) {
                ylength += end - start;
                start = ylines[i].second.first;
                end = ylines[i].second.second;
            } else if (ylines[i].second.second > end) {
                end = ylines[i].second.second;
            }
        }
        ylength += end - start;
        return ylength;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector< vector<int> > valueGrid;

    // variable
    int n;
    int nn;
    vector<int> valueLine;
    int value;

    // input
    cin >> n;
    while (n-- > 0) {
        cin >> nn;
        valueLine.clear();
        while (nn-- > 0) {
            cin >> value;
            valueLine.push_back(value);
        }
        valueGrid.push_back(valueLine);
    }

    Solution solution;
    cout << solution.rectangleArea(valueGrid) << endl;

    return 0;
}
