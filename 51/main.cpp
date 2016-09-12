#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
	void solveNQueens(vector<int>& column,
						vector<int>& pivot1,
						vector<int>& pivot2,
						int n,
						int x,
						vector< vector<string> >& results,
						vector<int>& pos)
	{
		for (int y=0; y<n; ++y) {
			if (column[y] && pivot1[x+y] && pivot2[x + n - 1 - y]) {
				if (n - 1 == x) {
					vector<string> result;
					for (int i=0; i<pos.size(); ++i) {
						result.push_back(getString(pos[i], n));
					}
					result.push_back(getString(y, n));
					results.push_back(result);
				} else {
					column[y] = 0;
					pivot1[x+y] = 0;
					pivot2[x+n-y-1] = 0;
					pos.push_back(y);

					solveNQueens(column, pivot1, pivot2, n, x+1, results, pos);

					column[y] = 1;
					pivot1[x+y] = 1;
					pivot2[x+n-y-1] = 1;
					pos.pop_back();
				}
			}
		}
	}

    vector< vector<string> > solveNQueens(int n)
	{
		vector< vector<string> > results;
		vector<int> column(n, 1);
		vector<int> pivot1(n * 2 - 1, 1);
		vector<int> pivot2(n * 2 - 1, 1);
		vector<int> pos;

		solveNQueens(column, pivot1, pivot2, n, 0, results, pos);

		return results;
    }

	string getString(int pos, int n)
	{
		static vector<string> Q(n, string(n, '.'));
		static bool first = true;
		if (first) {
			for (int i=0; i<n; ++i) {
				Q[i][i] = 'Q';
			}
			first = false;
		}
		return Q[pos];
	}
};

int main(int argc, char* argv[])
{
	int n;
	cin >> n;

    Solution solution;
	vector< vector<string> > results = solution.solveNQueens(n);
	for (int i=0; i<results.size(); ++i) {
		for (int j=0; j<results[i].size(); ++j) {
			cout << results[i][j] << endl;
		}
		cout << endl;
	}

	cout << "size = " << results.size() << endl;

    return 0;
}
