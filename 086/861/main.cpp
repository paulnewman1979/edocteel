#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int> >& A) {
        int row = A.size();
        int col = A[0].size();
        int i = 1, j, sum;
        int powSum = 1;
        while (i < col) {
            powSum += powSum;
            ++i;
        }

        for (i = 0; i < row; ++i) {
            if (A[i][0] == 0) {
                for (j = 0; j < col; ++j) {
                    A[i][j] = 1 - A[i][j];
                }
            }
        }

        int result = powSum * row;
        for (j = 1; j < col; ++j) {
            powSum /= 2;
            sum = 0;
            for (i = 0; i < row; ++i) {
                sum += A[i][j];
            }
            result += powSum * ((sum + sum < row) ? (row - sum) : sum);
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector< vector<int> > valueGrid;

    // variable
    int n;
    int nn;
    vector<int> valueLine;
    int value;

    // input
    cin >> n;
    while (n-- > 0) {
        cin >> nn;
        valueLine.clear();
        while (nn-- > 0) {
            cin >> value;
            valueLine.push_back(value);
        }
        valueGrid.push_back(valueLine);
    }

    Solution solution;
    cout << solution.matrixScore(valueGrid) << endl;

    return 0;
}
