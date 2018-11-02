#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int count = 0;
        int i, j;
        int max;
        
        for (i = 0; i < grid.size(); ++i) {
            // xz
            max = 0;
            for (j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] > 0) ++count;    // xy
                if (grid[i][j] > max) max = grid[i][j];
            }
            count += max;
        }
        
        // yz
        for (j = 0; j < grid[0].size(); ++j) {
            max = 0;
            for (i = 0; i< grid.size(); ++i) {
                if (grid[i][j] > max) max = grid[i][j];
            }
            count += max;
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
    cout << solution.projectionArea(grid) << endl;

    return 0;
}
