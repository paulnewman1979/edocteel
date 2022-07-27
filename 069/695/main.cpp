#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        int height = grid.size();
        if (0 == height) return 0;
        int width = grid[0].size();
        if (0 == width) return 0;

        int maxArea = 0;
        int curArea = 0;
        vector< pair<int, int> > area;
        pair<int, int> point;
        int i, j;
        for (i = 0; i < height; ++i) {
            for (j = 0; j < width; ++j) {
                if (grid[i][j] == 1) {
                    area.push_back(make_pair(i, j));
                    curArea = 0;
                    while (area.size() > 0) {
                        point = area.back();
                        area.pop_back();
                        if (grid[point.first][point.second] == 2) continue;
                        grid[point.first][point.second] = 2;
                        //cout << "pos: " << point.first << " " << point.second << endl;
                        ++curArea;
                        if ((point.first > 0) && (grid[point.first - 1][point.second] == 1))
                            area.push_back(make_pair(point.first - 1, point.second));
                        if ((point.first + 1 < height) && (grid[point.first + 1][point.second] == 1))
                            area.push_back(make_pair(point.first + 1, point.second));
                        if ((point.second > 0) && (grid[point.first][point.second - 1] == 1))
                            area.push_back(make_pair(point.first, point.second - 1));
                        if ((point.second + 1 < width) && (grid[point.first][point.second + 1] == 1))
                            area.push_back(make_pair(point.first, point.second + 1));
                    }
                    if (curArea > maxArea) {
                        //cout << curArea << endl;
                        maxArea = curArea;
                    }
                }
            }
        }

        return maxArea;
    }
};

int main(int argc, char* argv[])
{
	vector< vector<int> > grid;
	vector<int> row;
	int n;

	cin >> n;
	while (n != -999999) {
		if (n == -999998) {
			grid.push_back(row);
			row.clear();
		} else {
			row.push_back(n);
		}

		cin >> n;
	}

    Solution solution;
	cout << solution.maxAreaOfIsland(grid) << endl;

    return 0;
}
