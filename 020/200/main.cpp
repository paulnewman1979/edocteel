#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int count = 0;
        int i, j;
        for (i = 0; i < grid.size(); ++i) {
            for (j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    markIsland(grid, i, j);
                }
            }
        }

        return count;
    }

private:
    void markIsland(vector<vector<char> >& grid, int i, int j) {
        grid[i][j] = '2';
        //if ((i > 0) && (j < grid[i].size())) {
        if ((i > 0) && (grid[i - 1][j] == '1')) {
            grid[i - 1][j] = '2';
            markIsland(grid, i - 1, j);
        }
        if ((i + 1 < grid.size()) && (grid[i + 1][j] == '1')) {
            grid[i + 1][j] = '2';
            markIsland(grid, i + 1, j);
        }
        if ((j > 0) && (grid[i][j - 1] == '1')) {
            grid[i][j - 1] = '2';
            markIsland(grid, i, j - 1);
        }
        if ((j + 1< grid[i].size()) && (grid[i][j + 1] == '1')) {
            grid[i][j + 1] = '2';
            markIsland(grid, i, j + 1);
        }
    }
};

int main(int argc, char* argv[])
{
    vector< vector<char> > grid;
    vector<char> line;

    int n;
    int n1;
    char value;
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
    cout << solution.numIslands(grid) << endl;

    return 0;
}
