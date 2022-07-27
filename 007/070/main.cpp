#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (1 == n) {
            return 1;
        } else if (2 == n) {
            return 2;
        }
        
        int count1 = 1;
        int count2 = 2;
        int i;
        for (i=3; i+1<=n; i+=2) {
            count1 += count2;
            count2 += count1;
        }
        if (n % 2 == 0) {
            return count2;
        } else {
            return count1 + count2;
        }
    }
};

int main(int argc, char* argv[])
{
	int n;

	cin >> n;
    Solution solution;
	cout << solution.climbStairs(n) << endl;

    return 0;
}
