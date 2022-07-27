#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int count = 0;
        int i, j;

        // first line
        if (grid[0][0] > 0) {
            count += (grid[0][0]<<2) + 2;
        }
        //cout << "0\t0\t" << count << endl;;
        for (j = 1; j < grid[0].size(); ++j) {
            if (grid[0][j] > 0) {
                count += (grid[0][j]<<2) + 2;
                count -= min(grid[0][j - 1], grid[0][j])<<1;
            }
            //cout << "0\t" << j << "\t" << count << endl;;
        }

        for (i = 1; i < grid.size(); ++i) {
            if (grid[i][0] > 0) {
                count += (grid[i][0]<<2) + 2;
                count -= min(grid[i - 1][0], grid[i][0])<<1;
            }
            //cout << i << "\t0\t" << count << endl;
            for (j = 1; j < grid[i].size(); ++j) {
                if (grid[i][j] > 0) {
                    count += (grid[i][j]<<2) + 2;
                    count -= min(grid[i][j - 1], grid[i][j])<<1;
                    count -= min(grid[i - 1][j], grid[i][j])<<1;
                }
                //cout << i << "\t" << j << "\t" << count << endl;
            }
        }
        return count;
    }
};

int main(int argc, char* argv[])
{
    vector< vector<int> > grid;
    vector<int> line;

    int n;
    int n1;
    int value;
    cin >> n;
    while (n > 0) {
        cin >> n1;
        line.clear();
        while (n1 > 0) {
            cin >> value;
            line.push_back(value);
            --n1;
        }
        grid.push_back(line);
        --n;
    }

    Solution solution;
    cout << solution.surfaceArea(grid) << endl;

    return 0;
}
