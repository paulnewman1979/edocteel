#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) {
            return 0;
        }

        int result = 0;
        while (n > 0) {
            result += n / 5;
            n = n / 5;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    Solution solution;
    cout << solution.trailingZeroes(n) << endl;

    return 0;
}
