#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> count(n + 1, 0);
        int i, j;
        count[0] = 1;
        count[1] = 1;
        for (i = 2; i <= n; ++i) {
            for (j = 0; j < i; ++j) {
                count[i] += count[j] * count[i - 1 - j];
            }
        }
        return count[n];
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    Solution solution;
    cout << solution.numTrees(n) << endl;

    return 0;
}
