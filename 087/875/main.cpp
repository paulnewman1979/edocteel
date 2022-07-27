#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int i, j;
        unsigned long long K = 0;
        for (i = 0; i < piles.size(); ++i) {
            K += piles[i];
        }
        K = (K - 1) / H + 1;
        j = H + 1;

        int start = K;
        int cur = 1;
        int end = K - 1;
        do {
            start = end;
            end = start + cur;
            j = 0;
            for (i = 0; i < piles.size(); ++i) {
                j += (piles[i] - 1) / end + 1;
            }
            cur = cur<<1;
        } while (j > H);

        while (start + 1 < end) {
            cur = (start + end) / 2;
            j = 0;
            for (i = 0; i < piles.size(); ++i) {
                j += (piles[i] - 1) / cur + 1;
            }
            if (j <= H) {
                end = cur;
            } else {
                start = cur;
            }
        }
        return end;
    }
};

int main(int argc, char* argv[])
{
    int H;
    vector<int> values;

    int n;
    int value;
    cin >> H;
    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.minEatingSpeed(values, H) << endl;

    return 0;
}
