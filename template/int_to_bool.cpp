#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (0 == n) {
            return false;
        }
        while ((n & 0x1) == 0) {
            n = n>>1;
        }
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    Solution solution;
    cout << (solution.isPowerOfTwo(n) ? "true" : "fales") << endl;

    return 0;
}
