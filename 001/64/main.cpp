#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {
		int n = grid.size();
		int m = 0;
        if ( (0 == n) ||
			(0 == (m=grid[0].size())) ) {
            return 0;
        }
        
		int i, j;
        vector<int> result(m);
		result[0] = grid[0][0];
		for (j=1; j<m; ++j) {
			result[j] = result[j-1] + grid[0][j];
		}
		
        for (i=1; i<n; ++i) {
			result[0] += grid[i][0];
            for (j=1; j<m; ++j) {
				if (result[j] > result[j-1]) {
					result[j] = result[j-1] + grid[i][j];
				} else {
					result[j] += grid[i][j];
				}
            }
        }
        
        return result[m-1];
    }
};

int main(int argc, char* argv[])
{
	vector< vector<int> > grid;
	vector<int> row;
	int n;

	cin >> n;
	while (n != -999999) {
		if (n == -999998) {
			grid.push_back(row);
			row.clear();
		} else {
			row.push_back(n);
		}

		cin >> n;
	}

    Solution solution;
	cout << solution.minPathSum(grid) << endl;

    return 0;
}
