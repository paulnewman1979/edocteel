#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int value;
        int i, j;

        for (i = 0; i < n/2; ++i) {
            for (j = i; j < n - i - 1; ++j) {
                value = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = value;
            }
        }
    }
};

int main(int argc, char* argv[])
{
	vector< vector<int> > matrix;
	vector<int> line;

	int n;
    int value;

	cin >> n;
    int i, j;
    i = 0;
	while (i < n) {
        j = 0;
        line.clear();
        while (j < n) {
            cin >> value;
            line.push_back(value);
            ++j;
        }
	    matrix.push_back(line);
        ++i;
	}

    Solution solution;
	solution.rotate(matrix);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
