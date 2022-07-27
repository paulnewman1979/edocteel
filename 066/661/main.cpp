#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size(), i, j, count;
        vector<vector<int>> results(m, vector<int>(n, 0));
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                results[i][j] = M[i][j];
                count = 1;
                if (i > 0) {
                    results[i][j] += M[i-1][j]; ++count;
                    if (j > 0) { results[i][j] += M[i-1][j-1]; ++count; }
                    if (j < n - 1) { results[i][j] += M[i-1][j+1]; ++count; }
                }
                if (i < m - 1) {
                    results[i][j] += M[i+1][j];
                    ++count;
                    if (j > 0) { results[i][j] += M[i+1][j-1]; ++count; }
                    if (j < n - 1) { results[i][j] += M[i+1][j+1]; ++count; }
                }
                if (j > 0) { results[i][j] += M[i][j - 1]; ++count; }
                if (j < n - 1) { results[i][j] += M[i][j + 1]; ++count; }
                results[i][j] /= count;
            }
        }
        return results;
    }
};

int main(int argc, char* argv[])
{
    // input
	vector<vector<int>> edges;
    Input(edges);

    // solution
    Solution solution;
	vector<vector<int>> results = solution.imageSmoother(edges);

    // output
    Output(results);

    return 0;
}
