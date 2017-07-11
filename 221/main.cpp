#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int i, j;
        int height = matrix.size();
        if (0 == height) {
            return 0;
        }
        int width = matrix[0].size();
        if (0 == width) {
            return 0;
        }

        vector<vector<int> > count(height, vector<int>(width, 0));
        int max = 0;
        for (j = 0; j < width; ++j) {
            if (matrix[0][j] == '1') {
                count[0][j] = 1;
                max = 1;
            }
        }

        int min;
        for (i = 1; i < height; ++i) {
            if (matrix[i][0] == '1') {
                count[i][0] = 1;
                if (max < 1) {
                    max = 1;
                }
            }
            for (j = 1; j < width; ++j) {
                if (matrix[i][j] == '1') {
                    min = (count[i][j-1] < count[i-1][j]) ? count[i][j-1] : count[i-1][j];
                    if (min > count[i-1][j-1]) {
                        min = count[i-1][j-1];
                    }
                    count[i][j] = min + 1;
                    if (min + 1 > max) {
                        max = min + 1;
                    }
                }
            }
        }

        return max * max;
    }
};

int main(int argc, char* argv[])
{
	vector< vector<char> > matrix;
	vector<char> row;
	char c;

	cin >> c;
	while (c != '.') {
		if (c == '-') {
			matrix.push_back(row);
			row.clear();
            cout << endl;
		} else {
			row.push_back(c);
            cout << c;
		}

		cin >> c;
	}

    Solution solution;
	cout << solution.maximalSquare(matrix) << endl;

    return 0;
}
