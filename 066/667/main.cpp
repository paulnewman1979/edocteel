#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int lower = 1;
        int upper = n;

        while (upper > k + 1) {
            result.push_back(upper--);
        }
        while (upper > lower) {
            result.push_back(upper--);
            result.push_back(lower++);
        }
        if (upper == lower) {
            result.push_back(upper);
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
    vector<int> result = solution.constructArray(n, k);
	for (unsigned int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}

    return 0;
}
