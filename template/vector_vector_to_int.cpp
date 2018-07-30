#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        return 0;
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
