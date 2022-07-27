#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <tgmath.h>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int i = 0;
        vector<int> nCount(10, 0);
        vector<int> pow2Count(10, 0);
        nCount[N % 10]++;
        //cout << "original: " << (N % 10) << ", times " << nCount[N % 10] << endl;
        N /= 10;
        unsigned long long pow10 = 1;
        while (N > 0) {
            nCount[N % 10]++;
            //cout << "original: " << (N % 10) << ", times " << nCount[N % 10] << endl;
            N /= 10;
            pow10 *= 10;
        }

        unsigned long long pow2 = 1;
        while (pow2 < pow10) pow2 = pow2<<1;

        pow10 *= 10;
        while (pow2 < pow10) {
            unsigned long long tmp = pow2;
            fill(pow2Count.begin(), pow2Count.end(), 0);

            //cout << "checking " << tmp << endl;
            while (tmp > 0) {
                pow2Count[tmp % 10]++;
                //cout << "check: " << (tmp % 10) << ", times " << pow2Count[tmp % 10] << endl;
                tmp /= 10;
            }
            for (i = 0; i < 10; i++) {
                if (pow2Count[i] != nCount[i]) break;
            }
            if (10 == i) {
                return true;
            }
            pow2 = pow2<<1;
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    Solution solution;
    cout << (solution.reorderedPowerOf2(n) ? "true" : "false") << endl;

    return 0;
}
