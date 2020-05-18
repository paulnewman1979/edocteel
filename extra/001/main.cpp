#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

// for an table m*n (m rows & n cols)
// find all the methods from (0, s) to (m - 1, e)
// it can only move left/right/up

using namespace std;

class Solution {
public:
	int findAllWays(const int m,
                    const int n,
                    const int s,
                    const int e) {
        vector<vector<int> > goUp(m, vector<int>(n, 0));
        int i, j, k;
        for (j = 0; j < n; ++j) {
            goUp[0][j] = 1;
        }

        for (i = 1; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                for (k = 0; k < j; ++k) {
                    goUp[i][j] += goUp[i-1][k];
                }
            }
        }

		return goUp[m - 1][e];;
    }
};

int main(int argc, char* argv[])
{
	int m;
	int n;
    int s;
    int e;

	cin >> m;
	cin >> n;
    cin >> s;
    cin >> e;

    Solution solution;
	cout << solution.findAllWays(m, n, s, e) << endl;

    return 0;
}
