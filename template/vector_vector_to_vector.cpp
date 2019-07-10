#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "Input.hh"
#include "Output.hh"

using namespace std;

class Solution {
public:
    vector<int> largestTriangleArea(vector<vector<int>>& points) {
        vector<int> ret;
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
    vector<int> retVec = solution.largestTriangleArea(valueGrid);

    // output
    Output(retVec);

    return 0;
}

