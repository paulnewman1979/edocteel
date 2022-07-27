#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
        int mask = 0xffffffff;
        int gap = n - m;
        while (gap > 0) {
            mask <<= 1;
            gap >>= 1;
        }

		return (m & n & mask);
    }
};

int main(int argc, char* argv[])
{
	int m;
	int n;
	cin >> m;
	cin >> n;

    Solution solution;
	cout << solution.rangeBitwiseAnd(m, n) << endl;

    return 0;
}
