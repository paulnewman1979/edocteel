#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        // KC(1, c) = c
        // KC(k, 1) = 1
        // KC(k, c) = KC(k-1, c-1) + KC(k, c-1) + 1
        if (1 == N) {
            return 1;
        }

        bool found = false;
        vector<vector<int> > KC(K);
        int k, c;
        for (k = 0; k < K; ++k) {
            KC[k].push_back(1);
        }

        c = 0;
        while (!found) {
            ++c;
            //cout << "c=" << c << endl;
            KC[0].push_back(c + 1);
            for (k = 1; k < K; ++k) {
                KC[k].push_back(KC[k - 1][c - 1] + KC[k][c - 1] + 1);
                //cout << "KC[" << k + 1 << "][" << KC[k].size() << "]=" << KC[k][c] << endl;
            }
            if (KC[k - 1][c] >= N) {
                break;
            }
        }

        return c + 1;
    }
};

int main(int argc, char* argv[])
{
    int N;
    int K;

    cin >> K;
    cin >> N;
 
    Solution solution;
    cout << solution.superEggDrop(K, N) << endl;

    return 0;
}
