#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ret = 0.0;
        return ret;
    }
};

template <typename baseType>
void loadGrid(vector<vector<baseType>>& valueGrid) {
    int x, y;
    baseType value;
    vector<baseType> valueVec;
    cin >> x;
    while (x-- > 0) {
        cin >> y;
        while (y-- > 0) {
            cin >> value;
            valueVec.push_back(value);
        }
        valueGrid.push_back(valueVec);
    }
}

template <>
void loadGrid(vector<vector<string>>& valueGrid) {
    int x, y;
    string value;
    vector<string > valueVec;
    cin >> x;
    while (x-- > 0) {
        cin >> y;
        while (y-- > 0) {
            getline(cin, value);
            valueVec.push_back(value);
        }
        valueGrid.push_back(valueVec);
    }
}

int main(int argc, char* argv[])
{
    // input
    vector< vector<int> > valueGrid;

    // handle input
    loadGrid(valueGrid);

    // ret
    Solution solution;
    double ret = solution.largestTriangleArea(valueGrid);

    // output
    cout << ret << endl;

    return 0;
}
