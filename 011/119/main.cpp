#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1, 0);
		result[0] = 1;
		int i;
		int j;
		int last;
		for (i=1; i<=rowIndex; ++i) {
			for (j=i; j>0; --j) {
				result[j] += result[j-1];
			}
		}

		return result;
    }
};

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
    Solution solution;
	vector<int> result;
	result = solution.getRow(n);

	int i;
	for (i=0; i<result.size(); ++i) {
		cout << result[i] << endl;
	}

    return 0;
}

