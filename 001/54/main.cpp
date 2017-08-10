#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector< vector<int> >& matrix) {
		vector<int> result;
		int xstart = 0;
		int xend = matrix[0].size();
		int ystart = 0;
		int yend = matrix.size();
		int x = 0;
		int y = 0;
		int direction = 0;

		if ((0 == matrix.size()) ||
			(0 == matrix[0].size()) ) {
			return result;
		}

		while ((xstart < xend) && (ystart < yend)) {
			if (direction == 0) {
				for (x=xstart; x<xend; ++x) {
					result.push_back(matrix[y][x]);
				}
				++ ystart;
				direction = 1;
				x = xend - 1;
			} else if (direction == 1) {
				for (y=ystart; y<yend; ++y) {
					result.push_back(matrix[y][x]);
				}
				-- xend;
				direction = 2;
				y = yend - 1;
			} else if (direction == 2) {
				for (x=xend - 1; x>=xstart; --x) {
					result.push_back(matrix[y][x]);
				}
				-- yend;
				direction = 3;
				x = xstart;
			} else if (direction == 3) {
				for (y=yend - 1; y>=ystart; --y) {
					result.push_back(matrix[y][x]);
				}
				++ xstart;
				direction = 0;
				y = ystart;
			}
		}
		return result;
    }
};

int main(int argc, char* argv[])
{
	vector< vector<int> > matrix;
	vector<int> row;
	int n;
	cin >> n;
	while (n != -999999) {
		if (n == -999998) {
			matrix.push_back(row);
			row.clear();
		} else {
			row.push_back(n);
		}
		cin >> n;
	}
	matrix.push_back(row);

    Solution solution;
	vector<int> result = solution.spiralOrder(matrix);
	int i;
	for (i=0; i<result.size() - 1; ++i) {
		cout << result[i] << ",";
	}
	cout << result[i] << endl;

    return 0;
}
