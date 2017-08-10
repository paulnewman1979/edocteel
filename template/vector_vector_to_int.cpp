#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
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
