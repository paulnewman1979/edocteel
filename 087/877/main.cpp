#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        if (piles.size() <= 2) return true;

        vector<vector<int> > winGap(2, vector<int>(piles.size(), 0));
        int index, lastIndex;
        int i;
        int leftWinGap, rightWinGap;
        for (i = 0; i + 2 <= piles.size(); ++i) {
            winGap[0][i] = (piles[i] > piles[i + 1]) ?
                piles[i] - piles[i + 1] : piles[i + 1] - piles[i];
        }

        lastIndex = 0;
        int size = 2;
        while (size < piles.size()) {
            index = 1 - lastIndex;
            for (i = 0; i + size + 2 <= piles.size(); ++i) {
                leftWinGap = piles[i] + min(winGap[lastIndex][i + 1] - piles[i + size + 1], winGap[lastIndex][i + 2] - piles[i + 1]);
                rightWinGap = piles[i + size + 1] + min(winGap[lastIndex][i] - piles[i + size], winGap[lastIndex][i + 1] - piles[i]);
                winGap[index][i] = max(leftWinGap, rightWinGap);
            }
            lastIndex = index;
            size += 2;
        }

        return (winGap[lastIndex][0] > 0);
    }
};

int main(int argc, char* argv[])
{
    vector<int> values;

    int n;
    int value;
    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << (solution.stoneGame(values) ? "true" : "false") << endl;

    return 0;
}
