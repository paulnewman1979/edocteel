#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (0 == matrix.size() || 0 == matrix[0].size()) return false;
        return searchMatrix(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }

    bool searchMatrix(vector<vector<int> >& matrix,
                    int target,
                    int left,
                    int right,
                    int bottom,
                    int top) {
        if ((right < left) || (top < bottom)) return false;
        if ((left == right) && (bottom == top)) return matrix[left][bottom] == target;
        int lmedian= (left + right) / 2;
        int bmedian = (bottom + top) / 2;
        if (matrix[lmedian][bmedian] < target) {
            return searchMatrix(matrix, target, lmedian + 1, right, bottom, top) ||
                searchMatrix(matrix, target, left, lmedian , bmedian + 1, top);
        } else if (matrix[lmedian][bmedian] > target) {
            return searchMatrix(matrix, target, left, lmedian - 1, bottom, top) ||
                searchMatrix(matrix, target, lmedian, right, bottom, bmedian - 1); 
        } else {
            return true;
        }
    }
};

int main(int argc, char* argv[])
{
    vector< vector<int> > matrix;
    vector<int> row;
    int target;
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
    cout << (solution.searchMatrix(matrix, target) ? "true" : "false") << endl;

    return 0;
}
