#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        vector< vector<int> > result;
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
    vector< vector<int> > result = solution.combine(n, k);
	for (unsigned int i = 0; i < result.size(); ++i) {
        for (unsigned int j = 0; j < result[i].size(); ++j) {
    		cout << result[i][j] << " ";
        }
        cout << endl;
	}

    return 0;
}
