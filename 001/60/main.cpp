#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string result;
		vector<bool> mark(n, true);
		vector<int> countSum(n+1, 1);
		int i;
		int j;
		int count = 1;
		for (i=2; i<=n; ++i) {
			count *= i;
			countSum[i] = count;
		}

		if (k > countSum[n]) {
			return result;
		}

		int index;
		for (i=n; i>0; --i) {
			count = (k - 1) / countSum[i-1];
			index = -1;
			j = 0;
			while ((index < count) &&
					(j < n)) {
				if (mark[j]) {
					++ index;
				}
				++ j;
			}
			if (index == count) {
				result += ('0' + j);
				mark[j-1] = false;
			}
			k = (k-1) % countSum[i-1] + 1;
		}

		return result;
    }
};

int main(int argc, char* argv[])
{
	int n;
	int k;
	cin >> n;
	cin >> k;

    Solution solution;
	cout << solution.getPermutation(n,k) << endl;

    return 0;
}
