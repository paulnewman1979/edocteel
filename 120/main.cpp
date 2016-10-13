#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {
		if ((triangle.size() == 0) || 
			triangle[0].size() == 0) {
			return 0;
		}

		int i, j;
		vector< vector<int> > curTotal;
		for (i=0; i<triangle.size(); ++i) {
			curTotal.push_back(vector<int>(i+1, -1));
		}

		minimumTotal(triangle, curTotal, 0, 0);

		return curTotal[0][0];
    }

	void minimumTotal(const vector< vector<int> > & triangle,
		vector< vector<int> >& curTotal, const int x, const int y) {
		if (curTotal[x][y] != -1) {
		}
		else if (x == triangle.size() - 1) {
			curTotal[x][y] = triangle[x][y];
		} else {
			if (curTotal[x+1][y] == -1) {
				 minimumTotal(triangle, curTotal, x + 1, y);
			}
			if (curTotal[x+1][y+1] == -1) {
				 minimumTotal(triangle, curTotal, x + 1, y + 1);
			}
			curTotal[x][y] = triangle[x][y] + ((curTotal[x+1][y]>curTotal[x+1][y+1])?curTotal[x+1][y+1]:curTotal[x+1][y]);
		}
	}
};

int main(int argc, char* argv[])
{
	vector< vector<int> > triangle;
	vector<int> row;
	int n;

	cin >> n;
	while (n != -999999) {
		if (n == -999998) {
			triangle.push_back(row);
			row.clear();
		} else {
			row.push_back(n);
		}

		cin >> n;
	}

    Solution solution;
	cout << solution.minimumTotal(triangle) << endl;

    return 0;
}
