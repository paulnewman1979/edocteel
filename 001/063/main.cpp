#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
		int n = obstacleGrid.size();
		int m = 0;
        if ( (0 == n) ||
			(0 == (m=obstacleGrid[0].size())) ) {
            return 0;
        }
        
		int i, j;
        vector<int> result(m, 1);
		
		bool obstacle = false;
		for (j=0; j<m; ++j) {
			if (obstacle) {
				result[j] = 0;
			} else if (obstacleGrid[0][j] == 1) {
				result[j] = 0;
				obstacle = true;
			}
		}

        for (i=1; i<n; ++i) {
			if (obstacleGrid[i][0] == 1) {
				result[0] = 0;
			}
            for (int j=1; j<m; ++j) {
				if (obstacleGrid[i][j] == 1) {
					result[j] = 0;
				} else {
	                result[j] += result[j-1];
				}
            }
        }
        
        return result[m-1];
    }
};

int main(int argc, char* argv[])
{
	vector< vector<int> > obstacleGrid;
	vector<int> row;
	int n;

	cin >> n;
	while (n != -999999) {
		if (n == -999998) {
			obstacleGrid.push_back(row);
			row.clear();
		} else {
			row.push_back(n);
		}

		cin >> n;
	}

    Solution solution;
	cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
