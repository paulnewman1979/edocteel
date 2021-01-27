#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<vector<int> > results;
        return results;
    }
};

int main(int argc, char* argv[])
{
    // input
	vector< vector<int> > valueGrid;
    Input(valueGrid);

    // solution
    Solution solution;
	vector<vector<int> > results = solution.outerTrees(valueGrid);

    // output
    Output(results);

    return 0;
}
