#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> largestTriangleArea(vector<vector<int>>& points) {
        vector<int> ret;
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
    vector<int> retVec = solution.largestTriangleArea(valueGrid);

    // output
    for (auto p : retVec) {
        cout << p << endl;
    }

    return 0;
}

