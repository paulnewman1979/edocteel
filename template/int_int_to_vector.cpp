#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
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
    vector<int> result = solution.constructArray(n, k);
	for (unsigned int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}

    return 0;
}
