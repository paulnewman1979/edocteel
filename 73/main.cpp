#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector< vector<int> >& matrix) {
        int sizeX = matrix.size();
        int sizeY = matrix[0].size();
        
        vector<int> yVec(sizeY, 1);
        int x;
        int y;
        bool found = false;
        for (x=0; x<sizeX; ++x) {
            found = false;
            for (y=0; y<sizeY; ++y) {
                if (matrix[x][y] == 0) {
                    found = true;
                    yVec[y] = 0;
                }
            }
            if (found) {
                for (y=0; y<sizeY; ++y) {
                    matrix[x][y] = 0;
                }
            }
        }
        
        for (y=0; y<sizeY; ++y) {
            if (yVec[y] == 0) {
                for (x=0; x<sizeX; ++x) {
                    matrix[x][y] = 0;
                }
            }
        }
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

    Solution solution;
	solution.setZeroes(matrix);
	int i;
	int j;
	for (i=0; i<matrix.size(); ++i) {
		for (j=0; j+1<matrix[0].size(); ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << matrix[i][j] << endl;
	}

    return 0;
}
