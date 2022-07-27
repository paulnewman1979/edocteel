#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > transpose(vector<vector<int>>& A) {
        vector<vector<int> > results(A[0].size(), vector<int>(A.size()));
        int i, j;
        for (i = 0; i < A.size(); ++i) {
            for (j = 0; j < A[i].size(); ++j) {
                results[j][i] = A[i][j];
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
	vector<vector<int> > results = solution.transpose(edges);
    int i, j;
    for (i = 0; i < results.size(); ++i) {
        for (j = 0; j < results[i].size() - 1; ++j) {
            cout << results[i][j] << "\t";
        }
        cout << results[i][j] << endl;
    }

    return 0;
}
