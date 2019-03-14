#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int> > results;
        return results;
    }
};

int main(int argc, char* argv[])
{
    // parameters
    string S;

    // init data
    getline(cin, S);

    Solution solution;
	vector<vector<int> > results = solution.largeGroupPositions(S);
    for (int i = 0; i < results.size(); ++i) {
        for (int j = 0; j < results[i].size(); ++i) {
            cout << results[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
