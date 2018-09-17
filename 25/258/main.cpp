#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return (num - 1) % 9 + 1;
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    Solution solution;
    cout << solution.addDigits(n) << endl;

    return 0;
}
