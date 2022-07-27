#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        int i, j, digit;        
        for (i = left; i <= right; ++i) {
            j = i;
            while ((j > 0) && (j % 10 != 0)) {
                digit = j % 10;                
                if (i % digit != 0) break;
                j /= 10;
            }
            if (j == 0) ret.push_back(i);
        }
        return ret;
    }    
};

int main(int argc, char* argv[])
{
	int left;
    int right;
	cin >> left;
    cin >> right;

    Solution solution;
    vector<int> result = solution.selfDividingNumbers(left, right);
	for (unsigned int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}

    return 0;
}
