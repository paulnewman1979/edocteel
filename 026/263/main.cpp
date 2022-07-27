#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (0 == num) return false;

        while (num % 5 == 0) {
            num /= 5;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 2 == 0) {
            num /= 2;
        }

        return (num == 1);
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    Solution solution;
    cout << (solution.isUgly(n) ? "true" : "false") << endl;

    return 0;
}
