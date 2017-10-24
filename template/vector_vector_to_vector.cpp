#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> result;
        return result;
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
	edge = solution.findRedundantDirectedConnection(edges);
    for (int i = 0; i < edge.size(); ++i) {
        cout << edge[i] << endl;
    }
    cout << endl;

    return 0;
}
