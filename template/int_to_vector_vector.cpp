#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector< vector<int> > generate(int numRows) {
		vector< vector<int> > result;
		return result;
    }
};

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
    Solution solution;
	vector< vector<int> > result;
	result = solution.generate(n);
	for (int i=0; i<result.size(); ++i) {
		for (int j=0; j<result[i].size() - 1; ++j) {
			cout << result[i][j] << " ";
		}
		cout << result[i][j] << endl;
	}

    return 0;
}
