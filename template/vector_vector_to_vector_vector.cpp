#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<vector<int> > transpose(vector<vector<int>>& A) {
        vector<vector<int> > results;
        return results;
    }
};

int main(int argc, char* argv[])
{
    // input
	vector< vector<int> > edges;
    Input(edges);

    // solution
    Solution solution;
	vector<vector<int> > results = solution.transpose(edges);

    // output
    Output(results);

    return 0;
}
