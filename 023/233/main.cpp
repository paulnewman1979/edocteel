#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1) {
            return 0;
        }

        int count = 0;
        int digit;
        int rightNum = 0;
        int processSize = 1;

        while (n > 0) {
            digit = n % 10;
            n = n / 10;
            if (digit == 0) {
                count += n * processSize;
            } else if (digit > 1) {
                count += (n + 1) * processSize;
            } else {
                count += n * processSize + rightNum + 1;
            }
            rightNum += digit * processSize;
            processSize *= 10;
        }

        return count;
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    Solution solution;
    cout << solution.countDigitOne(n) << endl;

    return 0;
}
