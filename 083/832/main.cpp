#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        vector<vector<int> > results(row);
        int i, j;
        for (i = 0; i < row; ++i) {
            results[i].resize(col);
            for (j = 0; j < col; ++j) {
                results[i][j] = 1 - A[i][col - 1 - j];
            }
        }
        return results;
    }
};

int main(int argc, char* argv[])
{
	vector< vector<int> > edges;
	vector<int> edge;

	int n;
    int n1;
    int value;
	cin >> n;
	while (n > 0) {
        cin >> n1;
        edge.clear();
        while (n1 > 0) {
            cin >> value;
            edge.push_back(value);
            --n1;
        }
	    edges.push_back(edge);
        --n;
	}

    Solution solution;
	vector<vector<int> > results = solution.flipAndInvertImage(edges);
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i][0];
        for (int j = 1; j < results[i].size(); ++j) {
            cout << "\t" << results[i][j];
        }
        cout << endl;
    }

    return 0;
}
