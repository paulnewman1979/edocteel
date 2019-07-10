#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

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
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i][0];
        for (int j = 1; j < results[i].size(); ++j) {
            cout << "\t" << results[i][j];
        }
        cout << endl;
    }

    return 0;
}
