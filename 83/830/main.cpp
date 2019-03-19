#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int> > results;
        vector<int> result(2, 0);
        int i, start = 0;
        for (i = 1; i < S.length(); ++i) {
            if (S[i] != S[start]) {
                if (i >= start + 3) {
                    result[0] = start;
                    result[1] = i - 1;
                    results.push_back(result);
                }
                start = i;
            }
        }
        if (i >= start + 3) {
            result[0] = start;
            result[1] = i - 1;
            results.push_back(result);
        }
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
    int i;
    for (i = 0; i < results.size(); ++i) {
        cout << results[i][0] << "\t" << results[i][1] << endl;
    }

    return 0;
}
