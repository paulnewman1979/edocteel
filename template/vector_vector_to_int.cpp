#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    //int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int minRefuelStops(vector<vector<int>>& stations) {
        return 0;
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
    cout << solution.minRefuelStops(valueGrid) << endl;

    return 0;
}
