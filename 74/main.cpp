#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        int sizeX = matrix.size();
        if (0 == sizeX) {
            return false;
        }
        int sizeY = matrix[0].size();
        if (0 == sizeY) {
            return false;
        }
        
        int lower = 0;
        int higher = sizeX;
        int median;
        int x;
        if (target < matrix[0][0]) {
            return false;
        } else if (target == matrix[0][0]) {
            return true;
        } else if (target == matrix[sizeX-1][0]) {
            return true;
        } else if (target > matrix[sizeX-1][0]) {
            x = sizeX-1;
        } else {
            while (lower + 1 < higher) {
                median = (lower + higher + 1) / 2;
                if (target == matrix[median][0]) {
                    return true;
                } else if (target > matrix[median][0]) {
                    lower = median;
                } else {
                    higher = median;
                }
            }
            x = lower;
        }
        
        if (target == matrix[x][sizeY-1]) {
            return true;
        } else if (target > matrix[x][sizeY-1]) {
            return false;
        } else {
            lower = 0;
            higher = sizeY;
            while (lower + 1 < higher) {
                median = (lower + higher + 1) / 2;
                if (target == matrix[x][median]) {
                    return true;
                } else if (target > matrix[x][median]) {
                    lower = median;
                } else {
                    higher = median;
                }
            }
            
            return false;
        }
    }
};

int main(int argc, char* argv[])
{
	int target;
	vector< vector<int> > matrix;
	vector<int> row;
	int n;

	cin >> target;

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
	bool found = solution.searchMatrix(matrix, target);
	cout << (found?"true":"false") << endl;

    return 0;
}
