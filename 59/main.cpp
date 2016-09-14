#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
		int i, j;
		vector< vector<int> > result;
		if (0 == n) {
			return result;
		}

		for (i=0; i<n; ++i) {
			result.push_back(vector<int>(n, 0));
		}

		int start = 0;
		int end = n;
		int count = 1;
		for (i=0; i<n/2; i++) {
			start = i;
			end = n - i;
			for (j=start; j<end-1; ++j) {
				result[i][j] = count;
				++ count;
			}
			for (j=start; j<end-1; ++j) {
				result[j][end-1] = count;
				++ count;
			}
			for (j=end-1; j>start; --j) {
				result[end-1][j] = count;
				++ count;
			}
			for (j=end-1; j>start; --j) {
				result[j][start] = count;
				++ count;
			}
		}

		if (n % 2 == 1) {
			result[n/2][n/2] = count;
		}
		
		return result;
    }
};

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
    Solution solution;
	vector< vector<int> > result;
	result = solution.generateMatrix(n);
	for (int i=0; i<result.size(); ++i) {
		int j;
		for (j=0; j<result[i].size() - 1; ++j) {
			cout << result[i][j] << " ";
		}
		cout << result[i][j] << endl;
	}

    return 0;
}
