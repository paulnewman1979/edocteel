#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if ((m<=0) || (n<=0)) {
            return 0;
        }
        
        vector<int> result(m, 1);
        for (int i=2; i<=n; ++i) {
            for (int j=1; j<m; ++j) {
                result[j] += result[j-1];
            }
        }
        
        return result[m-1];
    }
};

int main(int argc, char* argv[])
{
	int m;
	int n;
	cin >> m;
	cin >> n;

    Solution solution;
	cout << solution.uniquePaths(m, n) << endl;

    return 0;
}
