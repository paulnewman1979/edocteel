#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;


class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastBit;
        int curBit;
        lastBit = n&1;
        n = n>>1;
        while (n > 0) {
            curBit = n&1;
            if (curBit == lastBit) return false;
            lastBit = curBit;
            n = n>>1;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    Solution solution;
    cout << (solution.hasAlternatingBits(n) ? "true" : "fales") << endl;

    return 0;
}
